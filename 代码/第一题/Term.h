//
// Created by Kqp1227 on 2022/6/21.
//

#ifndef DS_T_Q1_TERM_H
#define DS_T_Q1_TERM_H

#pragma once
#include <iostream>
using namespace std;

class Term {
public:
    float coef;  //多项式系数
    float pow;   //多项式指数
    Term* link;  //指向下一个多项式结点的指针
    //初始化多项式节点对象 c表示系数 p表示指数
    Term(float c, float p) : coef(c), pow(p), link(NULL) {} //构造函数
};

class Polynomial {
private:
    Term* first; //头节点
    void add(Term* pa, Term* pb, Term* pc);
    void sub(Term* pa, Term* pb, Term* pc);
    void mult(Term* pa, Term* pb, Term* pc);
public:
    Polynomial();
    Polynomial(Polynomial& po);
    ~Polynomial();
    void makeEmpty();
    friend istream& operator>>(istream& in, Polynomial& po);//输入重载
    friend ostream& operator<<(ostream& out, Polynomial& po);//输出重载
    Polynomial& operator+(Polynomial& po);
    Polynomial& operator-(Polynomial& po);
    Polynomial& operator*(Polynomial& po);
};


#endif //DS_T_Q1_TERM_H
