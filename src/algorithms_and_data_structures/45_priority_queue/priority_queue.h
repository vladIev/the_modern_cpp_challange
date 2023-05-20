#include <vector>
#include <algorithm>

template<typename T,
    typename Comparator = std::less<typename std::vector<T>::value_type>>
class PriorityQueue
{
  private:
    using value_type = typename std::vector<T>::value_type;
    using size_type = typename std::vector<T>::size_type;
    using reference = typename std::vector<T>::reference;
    using const_reference = typename std::vector<T>::const_reference;

  public:
    auto push(const T &el) -> void
    {
        d_data.push_back(el);
        std::push_heap(std::begin(d_data), std::end(d_data), d_comparator);
    }

    auto push(T &&el) -> void
    {
        d_data.push_back(std::move(el));
        std::push_heap(std::begin(d_data), std::end(d_data), d_comparator);
    }

    auto pop() -> void
    {
        std::pop_heap(std::begin(d_data), std::end(d_data), d_comparator);
        d_data.pop_back();
    }

    auto top() const -> const_reference { return d_data.front(); }
    auto size() const noexcept -> size_type { return d_data.size(); }
    auto empty() const noexcept -> bool { return d_data.empty(); }
    auto swap(PriorityQueue<T, Comparator> &other) noexcept -> void
    {
        d_data.swap(other.d_data);
        d_comparator.swap(other.d_comparator);
    }

  private:
    std::vector<T> d_data;
    Comparator d_comparator;
};


template<typename T, typename Comparator>
auto swap(PriorityQueue<T, Comparator> &lhs,
    PriorityQueue<T, Comparator> &rhs) noexcept(noexcept(lhs.swap(rhs)))
{
    lhs.swap(rhs);
}