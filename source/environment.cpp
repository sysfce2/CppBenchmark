/*!
    \file environment.cpp
    \brief Environment management static class implementation
    \author Ivan Shynkarenka
    \date 09.07.2015
    \copyright MIT License
*/

#include "environment.h"

#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

namespace CppBenchmark {

bool Environment::Is32BitOS()
{
    return !Is64BitOS();
}

bool Environment::Is64BitOS()
{
#if defined(_WIN64)
    return true;
#elif defined(_WIN32)
    BOOL bWow64Process = FALSE;
    return IsWow64Process(GetCurrentProcess(), &bWow64Process) && bWow64Process;
#endif
}

bool Environment::Is32BitProcess()
{
    return !Is64BitProcess();
}

bool Environment::Is64BitProcess()
{
#if defined(_WIN64)
    return true;
#elif defined(_WIN32)
    return false;
#endif
}

bool Environment::IsDebug()
{
    return !IsRelease();
}

bool Environment::IsRelease()
{
#if defined(NDEBUG)
    return true;
#else
    return false;
#endif
}

time_t Environment::Timestamp()
{
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

} // namespace CppBenchmark
