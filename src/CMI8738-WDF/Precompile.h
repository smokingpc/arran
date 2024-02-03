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

#include <ntddk.h>
#include <wdf.h>
#include <wdfminiport.h>
#include <initguid.h>

#include "PoolTag.h"
#include "Device.h"
#include "Queue.h"
#include "Trace.h"
#include "Driver.h"

#include "..\WdmUtils_output\WdmUtils.h"
#include "..\WdmUtils_output\AutoPtr.hpp"
