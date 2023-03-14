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

// �ݹ鷽ʽ���������
// n: arr�ĳ���
void HeapSort::adjust(int a, int index) {
    int left = 2 * index + 1; //index�����ӽڵ�
    int right = 2 * index + 2; //index�����ӽڵ�

    int maxIdx = index;
    if (left < a && arr[left] > arr[maxIdx]) maxIdx = left;
    if (right < a && arr[right] > arr[maxIdx]) maxIdx = right;

    if (maxIdx != index) {
        swap(arr[maxIdx], arr[index]);
        adjust(a, maxIdx);
    }

}

// ������
void HeapSort::heapSort() {
    // ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjust(n, i); //�������Ĵ���Ѹ��ڵ�Ϊ������������ i-��һ����Ҷ�ӽڵ���±�
    }

    // ���������
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);           //����ǰ���ķ��õ�����ĩβ �̶�ס ��ʣ��Ľ�������
        adjust(i, 0);              //δ�������Ĳ��ּ������ж�����
    }
}

void HeapSort::sort() {
    LARGE_INTEGER freq;//ѡ�񾫶ȸ��ߵļ�ʱ��
    LARGE_INTEGER start, end;
    double time;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    heapSort();
    QueryPerformanceCounter(&end);
    time = 1e3 * (end.QuadPart - start.QuadPart) / freq.QuadPart;
    cout << "��������ʱ��Ϊ��" << time << endl;
}

HeapSort::~HeapSort() {
    delete arr;
}