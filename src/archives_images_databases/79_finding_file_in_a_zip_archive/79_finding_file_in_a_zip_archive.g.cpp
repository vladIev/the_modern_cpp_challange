#include "79_finding_file_in_a_zip_archive.h"

#include "ZipFile.h"
#include "ZipArchive.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <iostream>
#include <iterator>

const auto archivePath = std::string("task79.zip");

TEST(maching_files_in_archive, test_archive_exists)
{
    const auto archive = ZipFile::Open(archivePath);
    ASSERT_THAT(archive, ::testing::NotNull());
}

TEST(maching_files_in_archive, matching_files)
{
    const auto pattern = R"(^.*\.jpg$)";
    const auto result = findMathcingFiles(archivePath, pattern);

    EXPECT_EQ(result.size(), 4);
}

TEST(maching_files_in_archive, throw_if_file_not_found)
{
    const auto pattern = R"(^.*\.jpg$)";
    EXPECT_THROW({ findMathcingFiles("", pattern); }, std::runtime_error);
}