#include <string>

#include "ZipFile.h"
#include "ZipArchive.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(ZipLib, breathing)
{
    const auto archive_path = std::string("task79.zip");
    auto archive = ZipFile::Open(archive_path);
    ASSERT_THAT(archive, ::testing::NotNull());
}