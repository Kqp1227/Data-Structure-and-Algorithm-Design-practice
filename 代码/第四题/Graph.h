//
// Created by 13439 on 2022/6/28.
//

#ifndef DS_T_Q4_GRAPH_H
#define DS_T_Q4_GRAPH_H

#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;



struct Edge {
    friend class Graph;
    int dest;
    float cost;
    float dist;
    Edge* link;
    Edge() :link(NULL) {}
};

struct City {
    friend class Graph;
    string name;
    bool visited;
    float mindist;
    float mindist_cost;
    float mincost;
    float mincost_dist;
    int path;
    Edge* first;
    City():first(NULL) {}
};

struct myStack {
    int length;
    string a[10];

    void create() {
        length = 0;
    }

    int size() {
        return length;
    }

    int empty() {
        if (length == 0) return true;
        else return false;
    }

    void push(string x) {
        a[++length] = x;
    }

    string top() {
        return a[length];
    }

    void pop() {
        if (length) length--;
    }
};

class Graph {
private:
    City* node;
    int n;
    int maxSize;
    void load();
    void reset();
public:
    Graph(int sz);
    ~Graph();
    float getCost(int v1, int v2);
    float getDist(int v1, int v2);
    int getCityPos(string name);
    void ShortCostPath(int v);
    void ShortDistPath(int v);
    void outputCostResult(int v1, int v2);
    void outputDistResult(int v1, int v2);

};


#endif //DS_T_Q4_GRAPH_H
