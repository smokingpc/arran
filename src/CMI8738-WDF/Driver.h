#pragma once
// ================================================================
// SpcNvme : OpenSource CMI8738 Audio Driver for Windows 10+
// Author : Roy Wang(SmokingPC).
// Licensed by MIT License.
// 
// Copyright (C) since 2024, Roy Wang (SmokingPC)
// https://github.com/smokingpc/
// 
// Contact Me : smokingpc@gmail.com
// ================================================================
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this softwareand associated documentation files(the "Software"), 
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and /or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions :
//
// The above copyright noticeand this permission notice shall be included in 
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
// IN THE SOFTWARE.
// ================================================================
// [Additional Statement]
// This is experimental Driver for CMI8738 audio card.
// I used PCIe version of this audio card to write this driver.
// You can copy, modify, redistribute the source code. 
// 
// PLEASE KEEP MY NAME in this codes.
// This is my only expectation for this project. :)
// 
// Enjoy it.
// ================================================================

//Device Interface GUID
DEFINE_GUID(GUID_DEVINTERFACE_CMI8738,
    0xd227e149, 0x37e5, 0x428e, 0x95, 0x24, 0xa2, 0x0f, 0x1c, 0x10, 0xdf, 0xef);

EXTERN_C_START
DRIVER_INITIALIZE DriverEntry;
DRIVER_UNLOAD DriverUnload;
_Dispatch_type_(IRP_MJ_PNP) DRIVER_DISPATCH PnpHandler;

#if 0
EVT_WDF_DRIVER_DEVICE_ADD CMI8738EvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP CMI8738EvtDriverContextCleanup;
#endif
EXTERN_C_END
