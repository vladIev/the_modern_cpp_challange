#include "61_parallel_transform.h"

#include <vector>
#include <set>
#include <mutex>
#include <thread>
#include <numeric>

#include <gtest/gtest.h>

TEST(parallel_transform, breathing)
{
    constexpr auto test_data_size = 1000u;
    const auto test_func = [](const auto el) { return el * el; };

    std::vector<int64_t> test_data(test_data_size);
    std::iota(std::begin(test_data), std::end(test_data), 0);
    auto test_data_copy = test_data;

    ptransform(std::begin(test_data_copy), std::end(test_data_copy), test_func);

    std::transform(std::begin(test_data),
        std::end(test_data),
        std::begin(test_data),
        test_func);

    EXPECT_EQ(test_data, test_data_copy);
}

TEST(parallel_transform, run_in_several_threads)
{
    constexpr auto test_data_size = 1000u;
    std::unordered_map<std::thread::id, uint32_t> threadsCntr;
    std::mutex mutex;
    const auto test_func = [&](const auto el) {
        std::lock_guard lg(mutex);
        threadsCntr[std::this_thread::get_id()]++;
        return el;
    };

    std::vector<int64_t> test_data(test_data_size);
    std::iota(std::begin(test_data), std::end(test_data), 0);

    ptransform(std::begin(test_data), std::end(test_data), test_func);

    EXPECT_GT(threadsCntr.size(), 1);
    const auto hardware_threads = std::thread::hardware_concurrency();
    if (hardware_threads != 0) {
        EXPECT_LE(threadsCntr.size(), hardware_threads);
    }
}