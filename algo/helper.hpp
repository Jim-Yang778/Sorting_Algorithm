#ifndef SORT_ALGORITHM_HELPER_HPP
#define SORT_ALGORITHM_HELPER_HPP
#include <utility>

template <typename T>
inline void swap(T &a, T &b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template <typename T>


#endif //SORT_ALGORITHM_HELPER_HPP
