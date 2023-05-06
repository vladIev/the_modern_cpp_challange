#include "ipv4.h"

#include <sstream>

#include <gtest/gtest.h>

const auto LOCALHOST_STR = std::string_view("127.0.0.1");
const auto LOCALHOST_INT = 2130706433;
TEST(IPV4_test, ipv4_str_constructor)
{
    Ipv4 ip(LOCALHOST_STR);
    EXPECT_EQ(ip.as_int(), LOCALHOST_INT);
    EXPECT_EQ(ip.as_string(), LOCALHOST_STR);
}

TEST(IPV4_test, ipv4_int_constructor)
{
    Ipv4 ip(LOCALHOST_INT);
    EXPECT_EQ(ip.as_int(), LOCALHOST_INT);
    EXPECT_EQ(ip.as_string(), LOCALHOST_STR);
}

TEST(IPV4_test, ipv4_copy_constructor)
{
    Ipv4 ip_src(LOCALHOST_INT);
    Ipv4 ip_copy = ip_src;
    EXPECT_EQ(ip_copy.as_int(), ip_src.as_int());
}

TEST(IPV4_test, ipv4_move_constructor)
{
    Ipv4 ip_src(LOCALHOST_INT);
    Ipv4 ip_copy = std::move(ip_src);
    EXPECT_EQ(ip_copy.as_int(), LOCALHOST_INT);
}

TEST(IPV4_test, ipv4_constructor_exception)
{
    const auto empty = "";
    EXPECT_THROW((void)Ipv4(empty), std::invalid_argument);

    const auto error_ip = "192.0.01";
    EXPECT_THROW((void)Ipv4(error_ip), std::invalid_argument);

    const auto letters = "192.O.0.1";
    EXPECT_THROW((void)Ipv4(letters), std::invalid_argument);

    const auto negative = "-1.0.0.1";
    EXPECT_THROW((void)Ipv4(negative), std::invalid_argument);

    const auto overflow = "265.0.0.1";
    EXPECT_THROW((void)Ipv4(overflow), std::invalid_argument);

    const auto five_parts = "192.0.0.1.0";
    EXPECT_THROW((void)Ipv4(five_parts), std::invalid_argument);
}

TEST(IPV4_test, istream)
{
    std::stringstream ss(LOCALHOST_STR.data());
    Ipv4 ip;
    ss >> ip;
    EXPECT_EQ(ip.as_string(), LOCALHOST_STR);
}

TEST(IPV4_test, ostream)
{
    std::stringstream ss;
    Ipv4 ip(LOCALHOST_STR.data());
    ss << ip;
    EXPECT_EQ(ss.str(), LOCALHOST_STR);
}