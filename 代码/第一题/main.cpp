//
// 问题1 - 稀疏多项式运算
// Created by Kqp1227 on 2022/6/21.
// 加法减法时间复杂度：O(n) 空间复杂度：O(n)
// 乘法的时间复杂度：O(n^2) 空间复杂度：O(n)
//

#include "Term.h"
#include <iostream>
using namespace std;

int main()
{
    Polynomial ap,bp;
    cin >> ap;
    cin >> bp;

    char op;
    cin >> op;
    switch (op)
    {
        case'+':
            cout << ap + bp;
            break;
        case'-':
            cout << ap - bp;
            break;
        case'*':
            cout << ap * bp;
            break;
        default:
            cout << "输入错误";
            break;
    }
}