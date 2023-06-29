#include <thread>
#include <vector>
#include <future>

auto get_num_of_threads(int64_t length, int64_t min_chunk_size = 32)
{
    const uint32_t max_threads =
        static_cast<uint32_t>((length + min_chunk_size - 1) / min_chunk_size);
    const uint32_t hardware_threads = std::thread::hardware_concurrency();
    return std::min(
        hardware_threads != 0u ? hardware_threads : 2u, max_threads);
}

template<typename Iterator, typename Func>
auto ptransform(Iterator begin, Iterator end, Func f) -> void
{
    const auto length = std::distance(begin, end);
    if (!length) { return; }

    const auto num_threads = get_num_of_threads(length);
    const auto chunk_size = length / num_threads;

    std::vector<std::future<void>> futures(num_threads - 1);
    std::vector<std::thread> threads(num_threads - 1);
    
    Iterator chunk_start = begin;
    for (auto i = 0u; i < num_threads - 1; i++) {
        Iterator chunk_end = chunk_start;
        std::advance(chunk_end, chunk_size);

        std::packaged_task<void(void)> task(
            [=]() { std::transform(chunk_start, chunk_end, chunk_start, f); });

        futures[i] = task.get_future();
        threads[i] = std::thread(std::move(task));
        chunk_start = chunk_end;
    }

    std::transform(chunk_start, end, chunk_start, f);

    for (auto &future : futures) { future.get(); }
    for (auto &thread : threads) { thread.join(); }

}