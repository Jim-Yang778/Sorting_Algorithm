#include "algos.hpp"
#include "helper.hpp"

void shellSort(std::vector<int> &list) {
    int len = list.size();

    // 大思路是分组进行insertion_sort
    //    分组的原则如下例子:
    //    1, 2, 3, 4, 5, 6
    //       (1) 第一次分, group_size = 3 = len / 2
    //           那么得到的是 [1, 4] [2, 5] [3, 6] 三组
    //       (2) 然后对这三个组分别进行插入排序
    //       (3) 修改 group_size = 1 = group_size / 2, 然后重复 (1), (2)直到 group_size = 0 时停止
    for (int step = len / 2; step > 0; step /= 2) {
        // i < group_size可以保证分组时不重复
        // 这个for进行分组
        for (int i = 0; i < step; ++i) {
            // 这个for开始对每一个组进行插入排序
            for (int j = i + step; j < len; j += step) {
                for (int pre = j - step; pre >= 0 && list[pre] > list[pre + step]; pre -= step) {
                    swap(list[pre], list[pre + step]);
                }
            }
        }
    }
}
