#include <iostream>
#include "HeapSort.h"

int main() {
    int mode;
    cout << "��������Դ�����";
    cin >> mode; //���Դ���
    for (int m = 0; m < mode; m++) {
        int n;
        cout << "������������������ĸ�����";
        cin >> n;
        HeapSort sortNum1(n);
        sortNum1.sort();
    }
    return 0;
}
