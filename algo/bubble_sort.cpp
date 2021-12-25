#include "algos.hpp"
#include "helper.hpp"

void bubbleSort(std::vector<int> &list) {
    for (int i = 0; i < list.size() - 1; ++i) {
        // 每进行一次能保证 list的倒数第 i 项是已经排好序的
        for (int j = 0; j < list.size() - 1 - i; ++j) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}
