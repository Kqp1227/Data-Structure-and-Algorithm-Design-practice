#include <iostream>
#include "HeapSort.h"

int main() {
    int mode;
    cout << "请输入测试次数：";
    cin >> mode; //测试次数
    for (int m = 0; m < mode; m++) {
        int n;
        cout << "请输入你想排序的数的个数：";
        cin >> n;
        HeapSort sortNum1(n);
        sortNum1.sort();
    }
    return 0;
}
