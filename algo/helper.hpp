#ifndef SORT_ALGORITHM_HELPER_HPP
#define SORT_ALGORITHM_HELPER_HPP

template <typename T>
inline void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

#endif //SORT_ALGORITHM_HELPER_HPP
