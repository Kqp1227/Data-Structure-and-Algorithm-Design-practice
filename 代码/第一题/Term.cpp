//
// Created by Kqp1227 on 2022/6/21.
//

#include "Term.h"
#include <iostream>

using namespace std;

istream &operator>>(istream &in, Polynomial &po) {
    //重载输入操作符
    int n;
    in >> n; //多项式项数
    Term *current = po.first; //初始化头节点
    float c, p;
    for (int i = 0; i < n; i++) {
        //按顺序输入项
        in >> c >> p; //输入每项的系数&指数
        current->link = new Term(c, p); //为新的多项式项申请结点
        current = current->link; //指向下一个多项式结点
    }
    return in;
}

ostream &operator<<(ostream &out, Polynomial &po) {
    Term *current = po.first->link; //运算结果多项式的第一个结点
    while (current) {
        out << current->coef << ' ' << current->pow << ' ';
        current = current->link;
    }
    return out;
}

void Polynomial::add(Term *pa, Term *pb, Term *pc) {
    Term *p1 = pa;
    Term *p2 = pb;
    Term *p3 = pc;
    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            float c = p1->coef + p2->coef;
            //c==0时该项不显示
            if (c) {
                //运算后产生的结点存入p3
                p3 = p3->link = new Term(c, p1->pow);
            }
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->pow < p2->pow) {
            //指数不相等 1号多项式结点直接存入p3
            p3 = p3->link = new Term(p1->coef, p1->pow);
            p1 = p1->link;
        } else {
            p3 = p3->link = new Term(p2->coef, p2->pow);
            p2 = p2->link;
        }
    }
    //1号多项式还未操作完
    if (p1) {
        while (p1) {
            p3 = p3->link = new Term(p1->coef, p1->pow);
            p1 = p1->link;
        }
    }
        //2号多项式还未操作完
    else {
        while (p2) {
            p3 = p3->link = new Term(p2->coef, p2->pow);
            p2 = p2->link;
        }
    }
}

void Polynomial::sub(Term *pa, Term *pb, Term *pc) {
    Term *pd = new Term(-1 * pb->coef, pb->pow); //2号多项式第一个结点
    Term *p4 = pd; //用来存储
    Term *p2 = pb->link; //2号多项式
    while (p2) {
        p4->link = new Term(-1 * p2->coef, p2->pow); //系数乘-1后存入p4
        p4 = p4->link;
        p2 = p2->link;
    }
    add(pa, pd, pc);
    while (p4) {
        p4 = pd->link;
        delete pd;
        pd = p4;
    }
}

void Polynomial::mult(Term *pa, Term *pb, Term *pc) {
    //每项分别相乘 再合并
    Term *p1 = pa;
    Term *p2 = pb;
    Term *p3 = pc;
    Term *p4;

    Term *ptemp = new Term(p2->coef, p2->pow); //存储第一个结点
    Term *pt = ptemp;
    //复制p2到ptemp
    while (p2->link) {
        p2 = p2->link;
        pt = pt->link = new Term(p2->coef, p2->pow);
    }
    while (p1) {
        //用第一个多项式的一个因数乘第二个多项式
        pt = ptemp;
        p2 = pb;
        while (pt) {
            pt->coef = p1->coef * p2->coef;
            pt->pow = p1->pow + p2->pow;
            pt = pt->link;
            p2 = p2->link;
        }
        //将这次乘法结果加到答案里
        p3 = pc->link;
        pc->link = NULL;
        add(ptemp, p3, pc);
        //释放p3的空间
        p4 = p3;
        while (p3) {
            p3 = p4->link;
            delete p4;
            p4 = p3;
        }
        //下一个因数
        p1 = p1->link;
    }
    //释放ptemp的空间
    pt = ptemp;
    while (ptemp) {
        ptemp = pt->link;
        delete pt;
        pt = ptemp;
    }
}

Polynomial::Polynomial() {
    first = new Term(-1, -1); //初始化
}

Polynomial::Polynomial(Polynomial &po) {
    first = new Term(-1, -1);
    //复制非零元
    Term *current = first;
    Term *pocurrent = po.first->link;
    while (pocurrent) {
        current = current->link = new Term(pocurrent->coef, pocurrent->pow);
        pocurrent = pocurrent->link;
    }
}

Polynomial::~Polynomial() {
    makeEmpty();
    delete first;
}

void Polynomial::makeEmpty() {
    //从头部进行删除结点回收
    Term *current = first->link;
    while (current) {
        first->link = current->link;
        delete current;
        current = first->link;
    }
}

Polynomial &Polynomial::operator+(Polynomial &po) {
    Polynomial *np = new Polynomial();
    //调用add方法
    Term *pa = this->first->link; //1号多项式的第一个多项式结点
    Term *pb = po.first->link; //2号多项式的第一个多项式结点
    Term *pc = np->first; //用于存储运算结果
    add(pa, pb, pc);
    return *np; //运算结果
}

Polynomial &Polynomial::operator-(Polynomial &po) {
    Polynomial *np = new Polynomial();
    //调用sub方法
    Term *pa = this->first->link;
    Term *pb = po.first->link;
    Term *pc = np->first;
    sub(pa, pb, pc);
    return *np;
}

Polynomial &Polynomial::operator*(Polynomial &po) {
    Polynomial *np = new Polynomial();
    //调用mult方法
    Term *pa = this->first->link;
    Term *pb = po.first->link;
    Term *pc = np->first;
    mult(pa, pb, pc);
    return *np;
}
