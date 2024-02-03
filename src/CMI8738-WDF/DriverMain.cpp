#include "Precompile.h"
#include "DriverEntry.tmh"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)

    #if 0
    #pragma alloc_text (PAGE, CMI8738EvtDeviceAdd)
    #pragma alloc_text (PAGE, CMI8738EvtDriverContextCleanup)
    #endif
#endif

//Audio Driver should Hook the driver unload of Audio Port Class driver
typedef void (*PORT_CLASS_DRIVER_UNLOAD) (PDRIVER_OBJECT);
PORT_CLASS_DRIVER_UNLOAD gPortClassDriverUnload = NULL;

EXTERN_C_START
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  drvobj, _In_ PUNICODE_STRING registry)
{
    WDF_DRIVER_CONFIG config = {0};
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    WDF_OBJECT_ATTRIBUTES attributes;
    // Initialize WPP Tracing
    WPP_INIT_TRACING(drvobj, registry);
    //TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

#if 0
    // Register a cleanup callback so that we can call WPP_CLEANUP when
    // the framework driver object is deleted during driver unload.
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = CMI8738EvtDriverContextCleanup;

    WDF_DRIVER_CONFIG_INIT(&config,
                           CMI8738EvtDeviceAdd);
#endif
    //Audio Stack has its own PortDriver(similar as Storport)
    //All event should be dispatch by AudioPort.
    //So init WDF with WdfDriverInitNoDispatchOverride, tell WDF
    //"do not intercept IRP". 
    WDF_DRIVER_CONFIG_INIT(&config, WDF_NO_EVENT_CALLBACK);
    config.DriverInitFlags |= WdfDriverInitNoDispatchOverride;
    config.DriverPoolTag = TAG_MINIPORT_ADAPTER;

    status = WdfDriverCreate(drvobj,
                             registry,
                             WDF_NO_OBJECT_ATTRIBUTES,
                             &config,
                             WDF_NO_HANDLE);

    if (!NT_SUCCESS(status)) {
//        TraceEvents(TRACE_LEVEL_ERROR, TRACE_DRIVER, "WdfDriverCreate failed %!STATUS!", status);
        WPP_CLEANUP(drvobj);
        return status;
    }

// To intercept stop/remove/surprise-remove.
    drvobj->MajorFunction[IRP_MJ_PNP] = PnpHandler;

    //
    // Hook the port class unload function
    //
    gPortClassDriverUnload = drvobj->DriverUnload;
    drvobj->DriverUnload = DriverUnload;

//    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");
    return status;
}
void DriverUnload (_In_ PDRIVER_OBJECT DriverObject)
{
    if (gPortClassDriverUnload != NULL)
        gPortClassDriverUnload(DriverObject);

    // Unload WDF driver object. 
    if (WdfGetDriver() != NULL)
        WdfDriverMiniportUnload(WdfGetDriver());
}

NTSTATUS PnpHandler (
    _In_ DEVICE_OBJECT* devobj,
    _Inout_ IRP* irp)
{
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    IO_STACK_LOCATION* stack = NULL;
    PortClassDeviceContext* ext;

    // Documented https://msdn.microsoft.com/en-us/library/windows/hardware/ff544039(v=vs.85).aspx
    // This method will be called in IRQL PASSIVE_LEVEL
#pragma warning(suppress: 28118)
    PAGED_CODE();

    ASSERT(NULL != devobj);
    ASSERT(NULL != irp);

    //
    // Check for the REMOVE_DEVICE irp.  If we're being unloaded, 
    // uninstantiate our devices and release the adapter common
    // object.
    //
    stack = IoGetCurrentIrpStackLocation(_Irp);

    switch (stack->MinorFunction)
    {
    case IRP_MN_REMOVE_DEVICE:
    case IRP_MN_SURPRISE_REMOVAL:
    case IRP_MN_STOP_DEVICE:
        ext = static_cast<PortClassDeviceContext*>(_DeviceObject->DeviceExtension);

        if (ext->m_pCommon != NULL)
        {
            ext->m_pCommon->Cleanup();

            ext->m_pCommon->Release();
            ext->m_pCommon = NULL;
        }
        break;

    default:
        break;
    }

    ntStatus = PcDispatchIrp(_DeviceObject, _Irp);

    return ntStatus;
}

#if 0
NTSTATUS CMI8738EvtDeviceAdd(_In_ WDFDRIVER driver, _Inout_ PWDFDEVICE_INIT devinit)
{
    NTSTATUS status;
    UNREFERENCED_PARAMETER(driver);

    PAGED_CODE();
    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");
    status = CMI8738CreateDevice(devinit);
    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

    return status;
}

VOID CMI8738EvtDriverContextCleanup(_In_ WDFOBJECT DriverObject)
{
    //this function is called when driver unload and cleanup all WDF driver context.
    UNREFERENCED_PARAMETER(DriverObject);

    PAGED_CODE();
    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    //
    // Stop WPP Tracing
    //
    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
}
#endif

EXTERN_C_END
