//
// Created by 13439 on 2022/6/28.
//

#include "Graph.h"

void Graph::load()
{
    ifstream infile;
    string c1, c2;
    int nc1, nc2;
    float c, d;
    infile.open("arcs.txt");
    while (!infile.eof()) {
        infile >> c1 >> c2;
        infile >> c >> d;
        nc1 = getCityPos(c1);
        nc2 = getCityPos(c2);
        if (nc1 == -1) {
            node[n].name = c1;
            node[n].first = nullptr;
            nc1 = n++;
        }
        if (nc2 == -1) {
            node[n].name = c2;
            node[n].first = nullptr;
            nc2 = n++;
        }
        //头部插入一条边
        Edge* ne = new Edge();
        ne->dest = nc2;
        ne->cost = c;
        ne->dist = d;
        ne->link = node[nc1].first;
        node[nc1].first = ne;
    }
    infile.close();
}

Graph::Graph(int sz)
{
    n = 0;
    maxSize = sz;
    node = new City[maxSize];
    load();
}

float Graph::getCost(int v1,int v2)
{
    int v;
    if (node[v1].first)
        v = node[v1].first->dest;
    Edge* p = node[v1].first;
    while ((v != v2) && (p = p->link)) {
        v = p->dest;
    }
    if (p)
        return p->cost;
    else
        return 888888;//不存在的大数
}

float Graph::getDist(int v1, int v2)
{
    int v;
    if (node[v1].first)
        v = node[v1].first->dest;
    Edge* p = node[v1].first;
    while ((v != v2) && (p = p->link)) {
        v = p->dest;
    }
    if (p)
        return p->dist;
    else
        return 888888;//不存在的大数
}

int Graph::getCityPos(string name)
{
    for (int i = 0; i < n; i++) {
        if (node[i].name == name)
            return i;
    }
    return -1;
}

void Graph::ShortCostPath(int v)
{
    float MAX = 888888;//不存在的大数

    int u = v;
    float min = MAX;
    for (int i = 0; i < n; i++) {
        node[i].mincost = getCost(v, i);
        node[i].mincost_dist = getDist(v,i);
        node[i].visited = false;
        if (node[i].mincost < MAX)
            node[i].path = v; //遍历找到最短的
        else node[i].path = -1;
    }
    node[v].visited = true;
    node[v].mincost = 0;
    node[v].mincost_dist = 0;
    for (int i = 0; i < n - 1; i++) {
        min = MAX;
        u = v;
        for (int j = 0; j < n; j++) {
            if (node[j].visited == false && node[j].mincost < min) {
                u = j;
                min = node[j].mincost;
            }
        }
        node[u].visited = true;
        for (int j = 0; j < n; j++) {
            if (node[j].visited == false && getCost(u, j) < MAX && getCost(u, j) + node[u].mincost < node[j].mincost) {
                node[j].mincost = node[u].mincost + getCost(u, j);
                node[j].mincost_dist = node[u].mincost_dist + getDist(u,j);
                node[j].path = u;
            }
        }
    }
}

void Graph::ShortDistPath(int v)
{
    float MAX = 888888;//不存在的大数

    int u = v;
    float min = MAX;
    for (int i = 0; i < n; i++) {
        node[i].mindist = getDist(v, i);
        node[i].mindist_cost = getCost(v,i);
        node[i].visited = false;
        if (node[i].mindist < MAX)
            node[i].path = v;
        else node[i].path = -1;
    }
    node[v].visited = true;
    node[v].mindist = 0;
    node[v].mindist_cost = 0;
    for (int i = 0; i < n - 1; i++) {
        min = MAX;
        u = v;
        for (int j = 0; j < n; j++) {
            if (node[j].visited == false && node[j].mindist < min) {
                u = j;
                min = node[j].mindist;
            }
        }
        node[u].visited = true;
        for (int j = 0; j < n; j++) {
            if (node[j].visited == false && getDist(u, j) < MAX && getDist(u, j) + node[u].mindist < node[j].mindist) {
                node[j].mindist = node[u].mindist + getDist(u, j);
                node[j].mindist_cost = node[u].mindist_cost + getCost(u,j);
                node[j].path = u;
            }
        }
    }
}

void Graph::outputCostResult(int v1, int v2)
{
    myStack sCost;
    cout << "cost优先：" << endl;
    sCost.create();
    sCost.push(node[v2].name);
    int v = node[v2].path;
    while (v != v1) {
        sCost.push(node[v].name);
        v = node[v].path;
    }
    sCost.push(node[v1].name);
    while (!sCost.empty()) {
        cout << sCost.top() << " ";
        sCost.pop();
    }
    cout << endl;


    cout << "最小cost为：" << node[v2].mincost << endl;
    cout << "此时的dist为：" << node[v2].mincost_dist << endl;
    cout << endl;



}

void Graph::outputDistResult(int v1, int v2)
{
    cout << "dist优先：" << endl;
    myStack sDist;
    sDist.create();
//    stack<string> cs;
    sDist.push(node[v2].name);
    int v = node[v2].path;
    while (v != v1) {
        sDist.push(node[v].name);
        v = node[v].path;
    }
    sDist.push(node[v1].name);
    while (!sDist.empty()) {
        cout << sDist.top() << " ";
        sDist.pop();
    }
    cout << endl;
    cout << "最小dist为：" << node[v2].mindist << endl;
    cout << "此时的cost为：" << node[v2].mindist_cost << endl;


}
void Graph::reset()
{
    for (int i = 0; i < n; i++) {
        node[i].visited = false;
        node[i].path = -1;
        node[i].mincost = 888888;
        node[i].mindist = 888888;
    }
}

Graph::~Graph() {
    reset();
}