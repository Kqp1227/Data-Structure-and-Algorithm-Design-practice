//
// Created by Kqp1227 on 2022/7/2.
//

#ifndef DS_T_Q6_2_HEAPSORT_H
#define DS_T_Q6_2_HEAPSORT_H

#include<iostream>
#include <windows.h>//使用高精度计时器

#define random(x) (rand()%x) //用于生成随机数列

using namespace std;

class HeapSort {
private:
    int n = 0;
    int* arr;
    void adjust(int a, int index);
    void heapSort();


public:
    HeapSort(int a);
    ~HeapSort();
    void sort();

};


#endif //DS_T_Q6_2_HEAPSORT_H
