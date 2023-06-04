#include "ZipFile.h"
#include "ZipArchive.h"

#include <vector>
#include <string>
#include <regex>
#include <filesystem>
#include <format>

auto findMathcingFilesInArchive(const ZipArchive::Ptr &archive,
    std::string_view pattern) -> std::vector<std::string>
{
    std::vector<std::string> result;
    auto regexp = std::regex(pattern.data());
    for (auto i = 0; i < archive->GetEntriesCount(); i++) {
        const auto entry = archive->GetEntry(i);
        if (entry && !entry->IsDirectory()) {
            const auto &name = entry->GetName();
            if (std::regex_match(name, regexp)) {
                result.push_back(entry->GetFullName());
            }
        }
    }
    return result;
}

auto findMathcingFiles(std::string_view archivePath, std::string_view pattern)
    -> std::vector<std::string>
{
    if (!std::filesystem::exists(archivePath)) {
        throw std::runtime_error(std::format("File {} not found", archivePath));
    }

    const auto archive = ZipFile::Open(archivePath.data());
    return findMathcingFilesInArchive(archive, pattern);
}
