#include <limits.h>
#include <math.h>
#include "algos.hpp"

void radixSort(std::vector<int> &list) {
    int max_value = INT_MIN;
    int min_value = INT_MAX;   // 使用min_value把所有数保证都是正数
    for (auto &each : list) {
        max_value = std::max(max_value, each);
        min_value = std::min(min_value, each);
    }
    // radix sort只在正整数中适用，所以如果出现负数要把所有的数都加上min_value + 1转成正数
    // 反正排序不会因为所有数都加了同一个数而改变结果
    int flag = false;
    if (min_value < 0) {
        flag = true;
        for (auto &each : list) {
            each += std::abs(min_value) + 1;
        }
        max_value += std::abs(min_value) + 1;
    }

    // 计算一个正整数max_value的位数
    int max_digit = 1 + std::log10(max_value);

    // 用十个buckets表示10个桶，buckets[x]中装本次循环中这个数位上是x的数
    std::vector<std::vector<int>> buckets(10, std::vector<int>{});
    int mod = 10;
    int dev = 1;
    for (int i = 0; i < max_digit; ++i, dev *= 10, mod *= 10) {
        for (int j = 0; j < list.size(); ++j) {
            // (num % mod) / dev 可以在迭代中获得每一位 [mod,dev] = [10, 1], [100, 10]...
            buckets[(list[j] % mod) / dev].emplace_back(list[j]);
        }
        int index = 0;
        // 把buckets中的数再放回list中
        for (int j = 0; j < buckets.size(); ++j) {
            for(auto &each : buckets[j]) {
                list[index++] = each;
            }
            buckets[j].clear();
        }
    }

    // 如果有负数，再把加上去的数再减回去
    if (flag) {
        for (auto &each : list) {
            each -= std::abs(min_value) + 1;
        }
    }
}