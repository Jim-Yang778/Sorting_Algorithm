#ifndef SORT_ALGORITHM_HELPER_HPP
#define SORT_ALGORITHM_HELPER_HPP

inline void swap(int &a, int &b) {
    if (a == b) return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

#endif //SORT_ALGORITHM_HELPER_HPP
