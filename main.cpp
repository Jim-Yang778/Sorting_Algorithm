#define CATCH_CONFIG_MAIN 
#define CATCH_CONFIG_FAST_COMPILE
#include <random>
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "algo/algos.hpp"

std::vector<int> init() {
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> random_item_num{0, 50};
    std::uniform_int_distribution<int> random_num{-90, 90};

    int item_num = 1000;
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
    BENCHMARK("bubbleSort") {
        bubbleSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Selection Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("selectionSort") {
        selectionSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Insertion Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("insertionSort") {
        insertionSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Shell Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("shellSort") {
        shellSort(random_list);
    };
    CHECK(tmp == random_list);
}


TEST_CASE("Merge Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("mergeSort") {
        mergeSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Quick Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("quickSort") {
        quickSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Heap Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("heapSort") {
        heapSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Counting Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("countingSort") {
        countingSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Bucket Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("bucketSort") {
        bucketSort(random_list);
    };
    CHECK(tmp == random_list);
}

TEST_CASE("Radix Sort Testing") {
    auto random_list = init();

    auto tmp = random_list;
    std::sort(tmp.begin(), tmp.end());
    BENCHMARK("radixSort") {
        radixSort(random_list);
    };
    CHECK(tmp == random_list);
}