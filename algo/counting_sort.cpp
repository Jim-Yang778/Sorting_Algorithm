#include <limits.h>
#include "algos.hpp"

void countingSort(std::vector<int> &list) {
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    // 找到list的最大值和最小值
    for (auto &each : list) {
        max_value = std::max(each, max_value);
        min_value = std::min(each, min_value);
    }

    // 创建一数组顺序存放list中每个值，counter的下标 = list[i] - min_value
    std::vector<int> counter(max_value - min_value + 1, 0);

    for (int i = 0; i < list.size(); ++i) {
        counter[list[i] - min_value]++;
    }

    int list_index = 0;
    // 在按顺序把counter中的值放回list
    for (int i = 0; i < counter.size(); ++i) {
        while (counter[i] > 0) {
            list[list_index++] = i + min_value;
            --counter[i];
        }
    }
}
