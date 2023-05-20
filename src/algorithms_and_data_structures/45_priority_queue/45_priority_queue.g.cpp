#include "priority_queue.h"

#include <gtest/gtest.h>

TEST(priority_queue_test, breathing)
{
    const std::vector<int> testData{ 1, 35, 3, 2, 10, 42, 68 };

    PriorityQueue<int> queue;
    EXPECT_TRUE(queue.empty());

    for (const auto el : testData) { queue.push(el); }
    EXPECT_EQ(queue.size(), testData.size());
    EXPECT_FALSE(queue.empty());

    std::vector<int> sortedTestData{ testData };
    std::sort(std::begin(sortedTestData),
        std::end(sortedTestData),
        std::greater<int>());
    for (const auto el : sortedTestData) {
        EXPECT_EQ(queue.top(), el);
        queue.pop();
    }
    EXPECT_TRUE(queue.empty());
}