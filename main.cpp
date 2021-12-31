#define CATCH_CONFIG_MAIN // NOLINT(readability-identifier-naming)
#define CATCH_CONFIG_FAST_COMPILE
#include <random>
#include <catch2/catch.hpp>
#include "algo/algos.hpp"

std::vector<int> init() {
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> random_item_num{0, 50};
    std::uniform_int_distribution<int> random_num{-90, 90};

    int item_num = random_item_num(engine);
    std::vector<int> random_list = {};
    while (item_num) {
        random_list.emplace_back(random_num(engine));
        --item_num;
    }
    return random_list;
}

TEST_CASE("Bubble Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    bubbleSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Selection Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    selectionSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Insertion Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    insertionSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Shell Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    shellSort(random_list);
    CHECK(tmp == random_list);
}


TEST_CASE("Merge Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    mergeSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Quick Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    quickSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Heap Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    heapSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Counting Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    countingSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Bucket Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    bucketSort(random_list);
    CHECK(tmp == random_list);
}

TEST_CASE("Radix Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    radixSort(random_list);
    CHECK(tmp == random_list);
}