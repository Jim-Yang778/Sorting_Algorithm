#ifndef SORT_ALGORITHM_HELPER_HPP
#define SORT_ALGORITHM_HELPER_HPP

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

#endif //SORT_ALGORITHM_HELPER_HPP
