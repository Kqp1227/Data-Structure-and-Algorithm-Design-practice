//
// ����4 - ���·��
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
        cout << "��������� �յ㣺������o t�˳���" << endl;
            cin >> c1 >> c2;
        if(c1=="o" && c2=="t") {
            break;
        }
        vCost1 = vDist1 = g.getCityPos(c1); //��Ӧ�����
        vCost2 = vDist2 = g.getCityPos(c2); //��Ӧ�����

        g.ShortCostPath(vCost1); //Ȩֵ��С·��
        g.outputCostResult(vCost1,vCost2);
        g.ShortDistPath(vDist1);
        g.outputDistResult(vDist1,vDist2);


    }
}
