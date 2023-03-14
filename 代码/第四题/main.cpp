//
// 问题4 - 最短路径
// Created by Kqp1227 on 2022/6/25.
//
//

#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph g(100);
    Graph g1(100);
    int vCost1,vCost2,vDist1,vDist2;
    while (true) {
        string c1, c2;
        cout << "请输入起点 终点：（输入o t退出）" << endl;
            cin >> c1 >> c2;
        if(c1=="o" && c2=="t") {
            break;
        }
        vCost1 = vDist1 = g.getCityPos(c1); //对应结点编号
        vCost2 = vDist2 = g.getCityPos(c2); //对应结点编号

        g.ShortCostPath(vCost1); //权值最小路径
        g.outputCostResult(vCost1,vCost2);
        g.ShortDistPath(vDist1);
        g.outputDistResult(vDist1,vDist2);


    }
}
