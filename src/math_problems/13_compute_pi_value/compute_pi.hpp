#include <random>

template<typename RandomEngine = std::mt19937,
    typename Distribution = std::uniform_real_distribution<>>
double computePi(RandomEngine &engine,
    Distribution &distribution,
    uint32_t samples = 1'000'000)
{
    auto inCircleSamplesCntr = 0u;

    for (auto i = 0; i < samples; i++) {
        auto x = distribution(engine);
        auto y = distribution(engine);
        if (y * y <= 1 - x * x) { inCircleSamplesCntr++; }
    }

    return 4.0 * inCircleSamplesCntr / samples;
}