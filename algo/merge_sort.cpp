#include "algos.hpp"

// 真正执行比较的函数
void merge(std::vector<int> &list, int left, int right) {
    int mid = left + (right - left) / 2;
    std::vector<int> tmp(right - left + 1, 0);

    int i = 0;
    int index_left = left;
    int index_right = mid + 1;
    // 理解一个点: 就是进入这个merge函数时, left~mid 和 mid + 1 ~ right是 分别排好序的
    // 接下来就是依次比较list中left~mid 和 mid + 1 ~ right位置的数, 小的放在tmp中更前面
    while (index_left <= mid && index_right <= right) {
        if (list[index_left] < list[index_right]) {
            tmp[i] = list[index_left];
            ++index_left;
        } else {
            tmp[i] = list[index_right];
            ++index_right;
        }
        ++i;
    }
    // 下面的两个while是处理上面比较中，left~mid 或 mid + 1 ~ right没放完的部分
    // 通常是只会进到其中一个while里面
    while (index_left <= mid) {
        tmp[i] = list[index_left];
        ++index_left;
        ++i;
    }
    while (index_right <= right) {
        tmp[i] = list[index_right];
        ++index_right;
        ++i;
    }
    // 把list[left]到list[right]中的值替换成tmp[0]到tmp[right - left]的值
    // 完成这一次的递归，返回上一层递归的时候list[left]到list[right]就是顺序的了
    for (int i = 0; i < right - left + 1; ++i) {
        list[left + i] = tmp[i];
    }
}

// 执行递归(分治)的函数
void mergeSort(std::vector<int> &list, int left, int right) {
    if (left == right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(list, left, mid);
    mergeSort(list, mid + 1, right);
    merge(list, left, right);
}

// 主函数
void mergeSort(std::vector<int> &list) {
    if (list.size() < 2) return;
    mergeSort(list, 0, list.size() - 1);
}