#ifndef CAESAR_CIPHER_88
#define CAESAR_CIPHER_88

#include <algorithm>
#include <cctype>
#include <iterator>
#include <string_view>

namespace {
static uint8_t ALPHABET_SIZE = 26;

class CeaserEncryptor
{
  private:
    uint8_t d_shift;

  public:
    CeaserEncryptor(uint8_t shift) : d_shift(shift % ALPHABET_SIZE) {}
    std::string operator()(std::string_view str) const
    {
        if (d_shift == 0) { return std::string(str); }

        std::string result;
        result.reserve(str.size());
        std::transform(std::begin(str),
            std::end(str),
            std::back_inserter(result),
            [this](auto c) -> char {
                if (std::isupper(c)) {
                    return 'A' + ((c - 'A' + d_shift) % ALPHABET_SIZE);
                }
                return c;
            });
        return result;
    }
};

class CeaserDecryptor
{
  private:
    uint8_t d_shift;

  public:
    CeaserDecryptor(uint8_t shift) : d_shift(shift % ALPHABET_SIZE) {}
    std::string operator()(std::string_view str) const
    {
        if (d_shift == 0) { return std::string(str); }

        std::string result;
        result.reserve(str.size());
        std::transform(std::begin(str),
            std::end(str),
            std::back_inserter(result),
            [this](auto c) -> char {
                if (std::isupper(c)) {
                    return 'A'
                        + (ALPHABET_SIZE + c - d_shift - 'A') % ALPHABET_SIZE;
                }
                return c;
            });
        return result;
    }
};
}// namespace

inline std::string ceaserEncrypt(std::string_view str, uint8_t shift)
{
    return CeaserEncryptor(shift)(str);
}

inline std::string ceaserDecrypt(std::string_view str, uint8_t shift)
{
    return CeaserDecryptor(shift)(str);
}

#endif