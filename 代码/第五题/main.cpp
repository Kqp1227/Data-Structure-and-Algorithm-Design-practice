//
// ����5 - hashmap���ʱ�
// Created by Kqp1227 on 2022/6/27.
// ʱ�临�Ӷȣ�O(1)
// �ռ临�Ӷȣ�O(n)
//

#include <iostream>
#include <string>
#include <fstream>
#include "wordCheck.h"

using namespace std;
//const int maxn = 109584;
//int total;
//string h[maxn + 1];

//int Hash(string x) {
//    int l = x.length();
//    int m = l / 2;
//    int t = (x[0] - 65) * 10000 + (x[m] - 65) * 100 + x[l - 1] - 65;   //ȡֵ����
//    return t % maxn;
//}
//
//void Insert(string x) {
//    int t = Hash(x);
//    while (h[t] != "" && h[t] != x) {
//        t++; //��λ���е�����λ��
//        if (t == maxn)
//            t = 0;
//    }
//    h[t] = x;
//}
//
//void Find(string x) {
//    int t = Hash(x);
//    int k = t;
//    string right;
//
//    while (h[t] != "" && h[t] != x) {
//        t++;
//        if (t == maxn)
//            t = 0;
//    }//ֱ�Ӷ�λλ��t
//    if (h[t] == ""){ //tλ�ÿ� ������ҵĵ��ʲ��ڱ���
//        cout << x << " is wrong" << endl;
////        cout << ", can change to: " << right << endl;
//        total++;
//    }
//}


int main() {

    ios::sync_with_stdio(false);
//    string s;
//    int id = 0;
//    ifstream in("dic.txt");
//    string line;
//    while (getline (in, s)) {
//        Insert(s);
//    }
//    in.close();
//    ifstream in2("doc.txt");
//    while (in2 >> s) {
//        if (s[s.length() - 1] == ',' || s[s.length() - 1] == ':' || s[s.length() - 1] == '.' || s[s.length() - 1] == '?') {
//            s = s.substr(0, s.length() - 1); //ȥ�����
//        }
//        for (int i = 0; i < s.length(); i++) { //ȫ��Сд
//            if (s[i] >= 'A' && s[i] <= 'Z') {
//                s[i] = s[i] + 32;
//            }
//        }
//        Find(s);
//    }
//    in2.close();
//    cout << "����" << total << "������" << endl;
    wordCheck check1;
    check1.buildHashmap();
    check1.findWrongwords();

    return 0;
}