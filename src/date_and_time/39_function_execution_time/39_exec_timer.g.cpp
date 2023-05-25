#include "exec_timer.h"
#include "concepts.h"

#include <chrono>
#include <gtest/gtest.h>


TEST(exec_timer_test, time)
{
    auto func = [](const auto &sleep_time) {
        std::this_thread::sleep_for(sleep_time);
    };
    auto sleep_time_s = std::chrono::seconds(1);
    EXPECT_EQ(exec_timer<std::chrono::seconds>::duration(func, sleep_time_s),
        sleep_time_s);

    auto sleep_time_ms = std::chrono::milliseconds(100);
    EXPECT_NEAR(
        exec_timer<std::chrono::milliseconds>::duration(func, sleep_time_ms)
            .count(),
        sleep_time_ms.count(),
        sleep_time_ms.count() * 0.15);
}