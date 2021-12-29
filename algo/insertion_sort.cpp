#include "algos.hpp"
#include "helper.hpp"

void insertionSort(std::vector<int> &list) {
    if (list.size() < 2) {
        return;
    }
    for (int i = 1; i < list.size(); ++i) {
        for (int pre = i - 1; pre >= 0 && list[pre] > list[pre + 1]; --pre) {
            // 理解上来说0 ~ pre - 1都已经是排序好的
            // 这个for循环就把pre位置的数插到0 ~ pre前面
            swap(list[pre], list[pre + 1]);
        }
    }
}
