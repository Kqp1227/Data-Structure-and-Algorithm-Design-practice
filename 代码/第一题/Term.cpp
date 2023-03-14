//
// Created by Kqp1227 on 2022/6/21.
//

#include "Term.h"
#include <iostream>

using namespace std;

istream &operator>>(istream &in, Polynomial &po) {
    //�������������
    int n;
    in >> n; //����ʽ����
    Term *current = po.first; //��ʼ��ͷ�ڵ�
    float c, p;
    for (int i = 0; i < n; i++) {
        //��˳��������
        in >> c >> p; //����ÿ���ϵ��&ָ��
        current->link = new Term(c, p); //Ϊ�µĶ���ʽ��������
        current = current->link; //ָ����һ������ʽ���
    }
    return in;
}

ostream &operator<<(ostream &out, Polynomial &po) {
    Term *current = po.first->link; //����������ʽ�ĵ�һ�����
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
            //c==0ʱ�����ʾ
            if (c) {
                //���������Ľ�����p3
                p3 = p3->link = new Term(c, p1->pow);
            }
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->pow < p2->pow) {
            //ָ������� 1�Ŷ���ʽ���ֱ�Ӵ���p3
            p3 = p3->link = new Term(p1->coef, p1->pow);
            p1 = p1->link;
        } else {
            p3 = p3->link = new Term(p2->coef, p2->pow);
            p2 = p2->link;
        }
    }
    //1�Ŷ���ʽ��δ������
    if (p1) {
        while (p1) {
            p3 = p3->link = new Term(p1->coef, p1->pow);
            p1 = p1->link;
        }
    }
        //2�Ŷ���ʽ��δ������
    else {
        while (p2) {
            p3 = p3->link = new Term(p2->coef, p2->pow);
            p2 = p2->link;
        }
    }
}

void Polynomial::sub(Term *pa, Term *pb, Term *pc) {
    Term *pd = new Term(-1 * pb->coef, pb->pow); //2�Ŷ���ʽ��һ�����
    Term *p4 = pd; //�����洢
    Term *p2 = pb->link; //2�Ŷ���ʽ
    while (p2) {
        p4->link = new Term(-1 * p2->coef, p2->pow); //ϵ����-1�����p4
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
    //ÿ��ֱ���� �ٺϲ�
    Term *p1 = pa;
    Term *p2 = pb;
    Term *p3 = pc;
    Term *p4;

    Term *ptemp = new Term(p2->coef, p2->pow); //�洢��һ�����
    Term *pt = ptemp;
    //����p2��ptemp
    while (p2->link) {
        p2 = p2->link;
        pt = pt->link = new Term(p2->coef, p2->pow);
    }
    while (p1) {
        //�õ�һ������ʽ��һ�������˵ڶ�������ʽ
        pt = ptemp;
        p2 = pb;
        while (pt) {
            pt->coef = p1->coef * p2->coef;
            pt->pow = p1->pow + p2->pow;
            pt = pt->link;
            p2 = p2->link;
        }
        //����γ˷�����ӵ�����
        p3 = pc->link;
        pc->link = NULL;
        add(ptemp, p3, pc);
        //�ͷ�p3�Ŀռ�
        p4 = p3;
        while (p3) {
            p3 = p4->link;
            delete p4;
            p4 = p3;
        }
        //��һ������
        p1 = p1->link;
    }
    //�ͷ�ptemp�Ŀռ�
    pt = ptemp;
    while (ptemp) {
        ptemp = pt->link;
        delete pt;
        pt = ptemp;
    }
}

Polynomial::Polynomial() {
    first = new Term(-1, -1); //��ʼ��
}

Polynomial::Polynomial(Polynomial &po) {
    first = new Term(-1, -1);
    //���Ʒ���Ԫ
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
    //��ͷ������ɾ��������
    Term *current = first->link;
    while (current) {
        first->link = current->link;
        delete current;
        current = first->link;
    }
}

Polynomial &Polynomial::operator+(Polynomial &po) {
    Polynomial *np = new Polynomial();
    //����add����
    Term *pa = this->first->link; //1�Ŷ���ʽ�ĵ�һ������ʽ���
    Term *pb = po.first->link; //2�Ŷ���ʽ�ĵ�һ������ʽ���
    Term *pc = np->first; //���ڴ洢������
    add(pa, pb, pc);
    return *np; //������
}

Polynomial &Polynomial::operator-(Polynomial &po) {
    Polynomial *np = new Polynomial();
    //����sub����
    Term *pa = this->first->link;
    Term *pb = po.first->link;
    Term *pc = np->first;
    sub(pa, pb, pc);
    return *np;
}

Polynomial &Polynomial::operator*(Polynomial &po) {
    Polynomial *np = new Polynomial();
    //����mult����
    Term *pa = this->first->link;
    Term *pb = po.first->link;
    Term *pc = np->first;
    mult(pa, pb, pc);
    return *np;
}
