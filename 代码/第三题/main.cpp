#include <iostream>
#include "HuffmanCode.h"

int main() {
    int n;
    cin >> n;
    HuffmanCode huff1(n);
    huff1.create();

    char arr1[n];
    getchar();
    cin >> arr1; //��������ַ�������
    char arr2[n];
    getchar();
    cin >> arr2; //��������ַ�������

    cout << arr1 << ' ';
    huff1.encoding(arr1);
    cout << arr2 << ' ';
    huff1.decoding(arr2);
    return 0;
}
