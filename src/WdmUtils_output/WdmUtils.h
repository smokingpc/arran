#pragma once
// ================================================================
// WdmUtils : WDM utility functions for CPP Support, AutoPointer...etc.
// This util can be used for WDF also. Support almost all Win2000+ versions.
// Author : Roy Wang(SmokingPC).
// Licensed by MIT License.
// 
// Copyright (C) 2024, Roy Wang (SmokingPC)
// https://github.com/smokingpc/
// 
// NVMe Spec: https://nvmexpress.org/specifications/
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
// PLEASE KEEP MY NAME in this codes.
// This is my only expectation for this project. :)
// 
// Enjoy it.
// ================================================================

void* operator new (size_t size, POOL_TYPE type, ULONG tag);
void* operator new[](size_t size, POOL_TYPE type, ULONG tag);
void operator delete(void* ptr, ULONG tag);

bool IsSupportedOS(ULONG major, ULONG minor = 0);

class CDebugCallInOut
{
private:
    static const int BufSize = 64;
    char* Name = NULL;
public:
    CDebugCallInOut(char* name);
    CDebugCallInOut(const char* name);
    ~CDebugCallInOut();
};


class CSpinLock{
public:
    CSpinLock(KSPIN_LOCK* lock, bool acquire = true);
    ~CSpinLock();

    void DoAcquire();
    void DoRelease();
protected:
    KSPIN_LOCK* Lock = NULL;
    KIRQL OldIrql = PASSIVE_LEVEL;
    bool IsAcquired = false;
};
class CQueuedSpinLock {
public:
    CQueuedSpinLock(KSPIN_LOCK* lock, bool acquire = true);
    ~CQueuedSpinLock();

    void DoAcquire();
    void DoRelease();
protected:
    KSPIN_LOCK* Lock = NULL;
    KIRQL OldIrql = PASSIVE_LEVEL;
    KLOCK_QUEUE_HANDLE QueueHandle;
    bool IsAcquired = false;
};
