//
// Created by Kqp1227 on 2022/6/29.
//

#ifndef DS_T_Q7_PRIM_H
#define DS_T_Q7_PRIM_H
#include <iostream>
#include <cstring>

#define INF 9999999

using namespace std;

class Prim {
public:

    Prim(int a);
    ~Prim();
    void run();

private:
    int n = 0;
    int **G;
};


#endif //DS_T_Q7_PRIM_H
