#include <algorithm>
#include <iterator>
#include <stdexcept>
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
    requires requires(Iterator beg, Iterator end, Func f) {
        {
            f(beg, end)
        } -> std::same_as<typename std::iterator_traits<Iterator>::value_type>;
    }
auto pengine(Iterator begin, Iterator end, Func func)
{
    using ValueType = typename std::iterator_traits<Iterator>::value_type;

    const auto length = std::distance(begin, end);
    if (!length) { throw std::runtime_error("Empty range"); }

    const auto numThreads = getNumOfThreads(length);
    const auto chunkSize = length / numThreads;

    std::vector<std::future<ValueType>> futures(numThreads - 1);
    std::vector<std::thread> threads(numThreads - 1);

    Iterator chunkStart = begin;
    for (auto i = 0U; i < numThreads - 1; i++) {
        Iterator chunkEnd = chunkStart;
        std::advance(chunkEnd, chunkSize);

        std::packaged_task<ValueType(Iterator, Iterator)> task(func);

        futures[i] = task.get_future();
        threads[i] = std::thread(std::move(task), chunkStart, chunkEnd);
        chunkStart = chunkEnd;
    }

    std::vector<ValueType> result;
    result.push_back(func(chunkStart, end));

    for (auto &future : futures) { result.push_back(future.get()); }
    for (auto &thread : threads) { thread.join(); }

    return func(result.begin(), result.end());
}

template<typename Iterator> auto pmin(Iterator begin, Iterator end)
{
    return pengine(
        begin, end, [](auto b, auto e) { return *std::min_element(b, e); });
}

template<typename Iterator> auto pmax(Iterator begin, Iterator end)
{
    return pengine(
        begin, end, [](auto b, auto e) { return *std::max_element(b, e); });
}