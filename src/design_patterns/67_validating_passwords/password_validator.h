#include <string_view>
#include <numeric>
#include <cctype>

template<typename T>
concept PasswordValidatorConcept = requires(T t) {
    {
        t(std::string_view{})
    } -> std::same_as<bool>;
};

template<size_t min, size_t max = std::numeric_limits<size_t>::max()>
struct LengthValidator
{
    auto operator()(std::string_view password) const noexcept -> bool
    {
        return password.size() >= min && password.size() <= max;
    }
};

template<size_t minUpper = 1, size_t minLower = 1> struct CaseValidator
{
    auto operator()(std::string_view password) const noexcept -> bool
    {
        size_t upperCntr = 0;
        size_t lowerCntr = 0;
        for (const auto &c : password) {
            if (upperCntr >= minUpper and lowerCntr >= minLower) {
                return true;
            }
            if (std::isupper(c)) upperCntr++;
            if (std::islower(c)) lowerCntr++;
        }

        return false;
    }
};

template<size_t minDigits = 1, size_t minLetters = 1, size_t minSigns = 1>
struct CharsValidator
{
  private:
    auto isValid(size_t numDigits,
        size_t numLetters,
        size_t numSigns) const noexcept -> bool
    {
        return numDigits >= minDigits && numLetters >= minLetters
            && minSigns >= numSigns;
    }

  public:
    auto operator()(std::string_view password) const noexcept -> bool
    {
        size_t digitsCntr = 0;
        size_t alphaCntr = 0;
        size_t signCntr = 0;
        for (const auto &c : password) {
            if (isValid(digitsCntr, alphaCntr, signCntr)) { return true; }
            if (std::isdigit(c)) {
                digitsCntr++;
            } else if (std::isalpha(c)) {
                alphaCntr++;
            } else {
                signCntr++;
            }
        }

        return false;
    }
};

template<PasswordValidatorConcept... Validators> struct PasswordValidator
{
    template<PasswordValidatorConcept... CustomValidators>
    static auto validate(std::string_view password,
        CustomValidators &&...customValidators) noexcept -> bool
    {
        static_assert(sizeof...(Validators) + sizeof...(customValidators) > 0,
            "Password validator can't have no rules");
        return (... && Validators()(password))
            && (...
                && std::forward<CustomValidators>(customValidators)(password));
    }
};
