#include "algos.hpp"
#include "helper.hpp"


void maxHeapify(std::vector<int>& list, int i, int len) {
    // while中的限定条件保证一次maxHeapify能持续地下沉，并持续交换更大的数到i的位置
    while ((i << 1) + 1 <= len) {
        // (i << 1) + 1 能找到 i 这个父节点的左子节点
        int left_son = (i << 1) + 1;
        // (i << 1) + 2 能找到 i 这个父节点的右子节点
        int right_son = (i << 1) + 2;
        int large;

        // 15~23行在找max(list[i], list[left_son], list[right_son]), 并把最大值的index保存到large /////
        if (left_son <= len && list[left_son] > list[i]) {
            large = left_son;
        } else {
            large = i;
        }

        if (right_son <= len && list[right_son] > list[large]) {
            large = right_son;
        }
        ///////////////////////////////////////////////////////////////////////////////////////////

        // 如果list[large]不是父节点，那么交换更大的那个到父节点
        // 1. 如果交换了，为了保证交换了之后的的子树还能维持最大堆的性质，所以把交换后的子节点的位置给到i，进行下一轮循环
        // 2. 如果本身list[large]就是父节点，那么说明从i开始往下的子树能持最大堆的性质，故跳出函数
        if (large != i) {
            swap(list[i], list[large]);
            i = large;
        } else {
            break;
        }
    }
}

// 创建最大堆：每一个父节点都永远比其子节点要大
void buildMaxHeap(std::vector<int>& list) {
    for (int i = ((list.size() - 1) >> 1); i >= 0; --i) {
        maxHeapify(list, i, list.size() - 1);
    }
}

void heapSort(std::vector<int> &list) {
    int len = list.size() - 1;
    // 1. 先把list创建成最大堆
    buildMaxHeap(list);
    // 2. 进入循环，创建了最大堆之后，根节点就是整个list中最大的数
    //    (1) 把这个数交换到list的末尾，并默认list的最后一位是固定的了，即list.size()减1
    //    (2) 重新把整个list调整成最大堆
    //    (3) 重复(1)(2)把第二大，第三大...的数从根节点交换到list[len]的位置直至最大堆只剩一个节点(根节点，此时i == 0)
    for (int i = len; i >= 1; --i) {
        swap(list[i], list[0]);
        --len;
        maxHeapify(list, 0, len);
    }
}
