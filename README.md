# Sorting_Algorithm

十大排序算法

main.cpp 用于测试（使用Catch2）

算法在algo文件夹中

需要用到的两个库的下载方式

Catch2 等于先下载好，后续cmake就能找到他了
```
git clone https://github.com/catchorg/Catch2.git
cd Catch2
cmake -B build -DBUILD_TESTING=OFF  # 关闭内置测试
cmake --build build -j8 --target install
```

spdlog 等于先下载好，后续cmake就能找到他了
```
git clone https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake .. && make -j$(nproc) && sudo make install
```