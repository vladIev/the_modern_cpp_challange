#include <thread>
#include <vector>
#include <future>

auto getNumOfThreads(int64_t length, int64_t minChunkSize = 32)
{
    const auto maxThreads =
        static_cast<uint32_t>((length + minChunkSize - 1) / minChunkSize);
    const uint32_t hardwareThreads = std::thread::hardware_concurrency();
    return std::min(hardwareThreads != 0U ? hardwareThreads : 2U, maxThreads);
}

template<typename Iterator, typename Func>
auto ptransform(Iterator begin, Iterator end, Func transformFunc) -> void
{
    const auto length = std::distance(begin, end);
    if (!length) { return; }

    const auto numThreads = getNumOfThreads(length);
    const auto chunkSize = length / numThreads;

    std::vector<std::future<void>> futures(numThreads - 1);
    std::vector<std::thread> threads(numThreads - 1);

    Iterator chunkStart = begin;
    for (auto i = 0U; i < numThreads - 1; i++) {
        Iterator chunkEnd = chunkStart;
        std::advance(chunkEnd, chunkSize);

        std::packaged_task<void(void)> task([=]() {
            std::transform(chunkStart, chunkEnd, chunkStart, transformFunc);
        });

        futures[i] = task.get_future();
        threads[i] = std::thread(std::move(task));
        chunkStart = chunkEnd;
    }

    std::transform(chunkStart, end, chunkStart, transformFunc);

    for (auto &future : futures) { future.get(); }
    for (auto &thread : threads) { thread.join(); }
}