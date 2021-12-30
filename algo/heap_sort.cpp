#include "algos.hpp"
#include "helper.hpp"


void maxHeapify(std::vector<int>& list, int i, int len) {
    while ((i << 1) + 1 <= len) {
        int left_son = (i << 1) + 1;
        int right_son = (i << 1) + 2;
        int large;

        if (left_son <= len && list[left_son] > list[i]) {
            large = left_son;
        } else {
            large = i;
        }

        if (right_son <= len && list[right_son] > list[large]) {
            large = right_son;
        }

        if (large != i) {
            swap(list[i], list[large]);
            i = large;
        } else {
            break;
        }
    }
}

void buildMaxHeap(std::vector<int>& list) {
    for (int i = (list.size() - 1) / 2; i >= 0; --i) {
        maxHeapify(list, i, list.size() - 1);
    }
}

void heapSort(std::vector<int> &list) {
    int len = list.size() - 1;
    buildMaxHeap(list);
    for (int i = len; i >= 1; --i) {
        swap(list[i], list[0]);
        --len;
        maxHeapify(list, 0, len);
    }
}
