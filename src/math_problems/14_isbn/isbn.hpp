#include <string>
#include <algorithm>
#include <numeric>
#include <cctype>

class IsbnValidator
{
  private:
    static bool validateSymbols(std::string_view isbn)
    {
        return isbn.size() == 10
            && !std::any_of(std::begin(isbn), std::end(isbn), [](auto ch) {
                   return !std::isdigit(ch);
               });
    }

    static bool validateCheckSum(std::string_view isbn)
    {
        auto weightedSum = std::accumulate(std::begin(isbn),
            std::end(isbn),
            0U,
            [weight = 10](auto sum, auto ch) mutable {
                return sum + (ch - '0') * weight--;
            });
        return weightedSum % 11 == 0;
    }

  public:
    static bool validate(std::string_view isbn)
    {
        return validateSymbols(isbn) && validateCheckSum(isbn);
    }
};