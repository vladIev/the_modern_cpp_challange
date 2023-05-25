#include "concepts.h"

#include <chrono>

template<typename Units = std::chrono::milliseconds,
    typename Timer = std::chrono::high_resolution_clock>
struct exec_timer
{
    template<typename F, typename... Args>
        requires utils::ReturnsNotVoid<F, Args>
    static auto duration(F &&f, Args &&...args)
    {
        auto start = Timer::now();

        decltype(auto) res =
            std::invoke(std::forward<F>(f), std::forward<Args>(args)...);

        return std::make_pair(
            std::chrono::duration_cast<Units>(Timer::now() - start),
            std::forward<decltype(res)>(res));
    }

    template<typename F, typename... Args>
        requires utils::ReturnsVoid<F, Args>
    static auto duration(F &&f, Args &&...args)
    {
        auto start = Timer::now();
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
        return std::chrono::duration_cast<Units>(Timer::now() - start);
    }
};