//
// Created by Kqp1227 on 2022/7/2.
//

#include "HeapSort.h"
HeapSort::HeapSort(int a) {
    n = a;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = random(10000);
    }
}

// 递归方式构建大根堆
// n: arr的长度
void HeapSort::adjust(int a, int index) {
    int left = 2 * index + 1; //index的左子节点
    int right = 2 * index + 2; //index的右子节点

    int maxIdx = index;
    if (left < a && arr[left] > arr[maxIdx]) maxIdx = left;
    if (right < a && arr[right] > arr[maxIdx]) maxIdx = right;

    if (maxIdx != index) {
        swap(arr[maxIdx], arr[index]);
        adjust(a, maxIdx);
    }

}

// 堆排序
void HeapSort::heapSort() {
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjust(n, i); //构建出的大根堆根节点为序列中最大的数 i-第一个非叶子节点的下标
    }

    // 调整大根堆
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);           //将当前最大的放置到数组末尾 固定住 对剩余的进行排序
        adjust(i, 0);              //未完成排序的部分继续进行堆排序
    }
}

void HeapSort::sort() {
    LARGE_INTEGER freq;//选择精度更高的计时器
    LARGE_INTEGER start, end;
    double time;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    heapSort();
    QueryPerformanceCounter(&end);
    time = 1e3 * (end.QuadPart - start.QuadPart) / freq.QuadPart;
    cout << "排序所用时间为：" << time << endl;
}

HeapSort::~HeapSort() {
    delete arr;
}