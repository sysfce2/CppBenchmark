/*!
    \file environment.h
    \brief Environment management static class definition
    \author Ivan Shynkarenka
    \date 09.07.2015
    \copyright MIT License
*/

#ifndef CPPBENCHMARK_ENVIRONMENT_H
#define CPPBENCHMARK_ENVIRONMENT_H

#include <ctime>

namespace CppBenchmark {

//! Environment management static class
/*!
    Provides environment management functionality to get OS bit version, process bit version, debug/release mode,
    timestamp, etc.
*/
class Environment
{
public:
    Environment() = delete;
    Environment(const Environment&) = delete;
    Environment(Environment&&) = delete;
    ~Environment() = delete;

    Environment& operator=(const Environment&) = delete;
    Environment& operator=(Environment&&) = delete;

    //! Is 32-bit OS?
    static bool Is32BitOS();
    //! Is 64-bit OS?
    static bool Is64BitOS();
    //! Is 32-bit running process?
    static bool Is32BitProcess();
    //! Is 64-bit running process?
    static bool Is64BitProcess();
    //! Is compiled in debug mode?
    static bool IsDebug();
    //! Is compiled in release mode?
    static bool IsRelease();

    //! Get the current timestamp
    static time_t Timestamp();
};

} // namespace CppBenchmark

#endif // CPPBENCHMARK_ENVIRONMENT_H
