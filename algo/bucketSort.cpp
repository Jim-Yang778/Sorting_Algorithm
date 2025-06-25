#include <limits.h>
#include "spdlog/spdlog.h"
#include "helper.hpp"
#include "algos.hpp"

void bucketSort(std::vector<int> &list) {
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    // 找到list的最大值和最小值
    for (auto &each : list) {
        max_value = std::max(each, max_value);
        min_value = std::min(each, min_value);
    }
    /////把数字放到 list.size()/4 个buckets里面
    int diff = max_value - min_value;

    int len = list.size() / 4;
    std::vector<std::vector<int>> buckets(len, std::vector<int>{});
    // 使用section 来划分进哪个buckets
    float section = (float)diff / (float)(len - 1);

    for (int i = 0; i < list.size(); ++i) {
        int num = (list[i] / section) - 1;
        num = num < 0 ? 0 : num;
        buckets[num].emplace_back(list[i]);
    }
    ///////////////////////////////////////////////////////////////

    // 对每个buckets进行一般的排序
    for (int i = 0; i < buckets.size(); ++i) {
        // 使用插入排序
        for (int j = 1; j < buckets[i].size(); ++j) {
            for (int pre = j - 1; pre >= 0 && buckets[i][pre] > buckets[i][pre + 1]; --pre) {
                swap(buckets[i][pre], buckets[i][pre + 1]);
            }
        }
    }

    // 把buckets中的数按序放回list
    int index = 0;
    for (int i = 0; i < buckets.size(); ++i) {
        for (auto &each : buckets[i]) {
            list[index++] = each;
        }
    }
}