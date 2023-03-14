// 问题7 - Prim生成最小生成树

#include <cstring>
#include <iostream>
#include "Prim.h"

using namespace std;

#define INF 9999999


int main() {
    int num;
    cin >> num;
    Prim prim1(num);
    prim1.run();
    return 0;
}