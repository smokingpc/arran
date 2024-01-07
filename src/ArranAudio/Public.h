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

DEFINE_GUID (GUID_DEVINTERFACE_ArranAudio,
    0x3f1f9c52,0xad24,0x4de0,0x83,0x44,0x4f,0xfc,0x9a,0x74,0x68,0x3b);
// {3f1f9c52-ad24-4de0-8344-4ffc9a74683b}
