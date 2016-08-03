//
// Created by Ivan Shynkarenka on 23.07.2015.
//

#include "benchmark/cppbenchmark.h"

#include <atomic>
#include <mutex>

const int iterations = 10000000;
const auto settings = CppBenchmark::Settings().Iterations(iterations).ThreadsRange(1, 8, [](int from, int to, int& result) { int r = result; result *= 2; return r; });

class UnsynchronizedFixture
{
protected:
    int counter;

    UnsynchronizedFixture() : counter(0) {}
};

class AtomicFixture
{
protected:
    std::atomic<int> counter;

    AtomicFixture() : counter(0) {}
};

class MutexFixture
{
protected:
    std::mutex mutex;
    int counter;

    MutexFixture() : mutex(), counter(0) {}
};

BENCHMARK_THREADS_FIXTURE(UnsynchronizedFixture, "unsynchronized++", settings)
{
    ++counter;
}

BENCHMARK_THREADS_FIXTURE(AtomicFixture, "std::atomic++", settings)
{
    ++counter;
}

BENCHMARK_THREADS_FIXTURE(MutexFixture, "std::mutex++", settings)
{
    std::lock_guard<std::mutex> lock(mutex);
    ++counter;
}

BENCHMARK_MAIN()
