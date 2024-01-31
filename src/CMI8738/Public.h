/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_CMI8738,
    0xd227e149,0x37e5,0x428e,0x95,0x24,0xa2,0x0f,0x1c,0x10,0xdf,0xef);
// {d227e149-37e5-428e-9524-a20f1c10dfef}
