#include <stdlib.h>
#include <time.h>
#include "algos.hpp"
#include "helper.hpp"

// 带随机的partition
int partition(std::vector<int> &list, int start, int end) {
    // 在start和end之间随机找一个数字作为基准pivot
    int rand_index = rand() % (end - start + 1) + start;
    swap(list[rand_index], list[end]);

    int pivot = list[end];
    int i = start;
    // 进入循环，比pivot小的都放在list[i]之前
    for (int j = start; j < end; ++j) {
        if (pivot > list[j]) {
            swap(list[j], list[i]);
            ++i;
        }
    }
    // 最后把pivot放到i的位置，区分开pivot左右两边的数
    swap(list[i], list[end]);
    // 返回pivot的坐标
    return i;
}

void quickSort(std::vector<int> &list, int start, int end) {
    if (start < end) {
        // 分治原理，partition运行结束后，pivot的左边都是比pivot小的，pivot的右边都是比pivot大的
        int pivot = partition(list, start, end);
        // 不需要在把pivot考虑在内因为pivot的位置是确定的
        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}

// 主函数 带随机的快排
void quickSort(std::vector<int> &list) {
    //srand设定随机种子
    srand((unsigned)time(NULL));
    quickSort(list, 0, list.size() - 1);
}