/*!
    \file launcher.h
    \brief Launcher base class definition
    \author Ivan Shynkarenka
    \date 07.07.2015
    \copyright MIT License
*/

#ifndef CPPBENCHMARK_LAUNCHER_H
#define CPPBENCHMARK_LAUNCHER_H

#include "benchmark.h"
#include "benchmark_pc.h"
#include "benchmark_threads.h"
#include "launcher_handler.h"
#include "reporter.h"

namespace CppBenchmark {

//! Launcher base class
/*!
    Provides interface to register benchmarks, launch them and report results with external reporters.
*/
class Launcher : public LauncherHandler
{
public:
    Launcher() = default;
    Launcher(const Benchmark&) = delete;
    Launcher(Benchmark&&) = delete;
    virtual ~Launcher() = default;

    Launcher& operator=(const Launcher&) = delete;
    Launcher& operator=(Launcher&&) = delete;

    //! Add the given benchmark to the benchmarks collection
    /*!
        \param benchmark - Benchmark to register
    */
    void AddBenchmark(std::shared_ptr<Benchmark> benchmark) { _benchmarks.emplace_back(benchmark); }
    //! Clear benchmarks collection
    void ClearAllBenchmarks() { _benchmarks.clear(); }

    //! Launch registered benchmarks
    /*!
        Launch benchmarks from the benchmarks collection which names are matched to the given string pattern. String
        pattern is represented with a regular expression.

        \param pattern - Pattern to match with benchmark names
    */
    virtual void Launch(const std::string& pattern = "");

    //! Report benchmarks results using the given reporter
    /*!
        \param reporter - Reporter interface
    */
    void Report(Reporter& reporter);

protected:
    //! Registered benchmarks collection
    std::vector<std::shared_ptr<Benchmark>> _benchmarks;

private:
    void ReportPhase(Reporter& reporter, const PhaseCore& phase, const std::string& name);
};

} // namespace CppBenchmark

#endif // CPPBENCHMARK_LAUNCHER_H
