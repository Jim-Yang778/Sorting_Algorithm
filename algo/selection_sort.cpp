#include "algos.hpp"
#include "helper.hpp"

void selectionSort(std::vector<int> &list) {
    int len = list.size();
    // len - 1是因为最后只剩一个数时不用比较
    for (int i = 0; i < len - 1; ++i) {
        // 每一轮的目标是找到一个从i开始往后走最小的
        int pre_min = i;
        for (int j = i + 1; j < len; ++j) {
            // 有比当前的list[pre_min]更小的
            if (list[j] <= list[pre_min]) {
                pre_min = j;
            }
        }
        swap(list[i], list[pre_min]);
    }
}
