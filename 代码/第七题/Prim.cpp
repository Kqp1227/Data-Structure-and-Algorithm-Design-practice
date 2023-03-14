//
// Created by Kqp on 2022/6/29.
//

#include "Prim.h"

Prim::Prim(int a) {
    G = new int *[a];
    for (int i = 0; i < a; i++) {
        G[i] = new int[a];
        for (int j = 0; j < a; j++) {
            int input = -1;
            cin >> input;
            G[i][j] = input;
        }
    }
    n = a;
}

void Prim::run() {
    int first = 0;
    cin >> first;
    int no_edge;  //边的个数
    no_edge = 0;
    int selected[n]; //记录选定的节点
    memset(selected, false, sizeof(selected)); //初始化都设为false
    selected[first] = true; //选择第0个节点

    int x; //行序号
    int y; //列序号

    cout << "Edge  : Weight" << endl;
    while (no_edge < n - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[first]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && G[i][j]) {  //没被选中且两节点间连通
                        if (min > G[i][j]) {
                            min = G[i][j]; //找到最小的
                            x = i; //记录行序号
                            y = j; //记录列序号
                        }
                    }
                }
            }
            first = (first + 1) % n;
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
}

Prim::~Prim() {
    delete G;
}