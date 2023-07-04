#include <random>
#include <ranges>

template<typename RandomEngine = std::mt19937,
    typename Distribution = std::uniform_real_distribution<>>
double computePi(RandomEngine &engine,
    Distribution &distribution,
    uint32_t samples = 1'000'000)
{
    auto in_circle_samples_cntr = 0U;

    for (auto i : std::views::iota(0U, samples)) {
        auto x = distribution(engine);
        auto y = distribution(engine);
        if (y * y <= 1 - x * x) { in_circle_samples_cntr++; }
    }

    return 4.0 * in_circle_samples_cntr / samples;
}