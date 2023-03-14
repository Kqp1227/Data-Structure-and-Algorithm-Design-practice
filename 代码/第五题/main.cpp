//
// 问题5 - hashmap单词表
// Created by Kqp1227 on 2022/6/27.
// 时间复杂度：O(1)
// 空间复杂度：O(n)
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
//    int t = (x[0] - 65) * 10000 + (x[m] - 65) * 100 + x[l - 1] - 65;   //取值方法
//    return t % maxn;
//}
//
//void Insert(string x) {
//    int t = Hash(x);
//    while (h[t] != "" && h[t] != x) {
//        t++; //该位置有单词则换位置
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
//    }//直接定位位置t
//    if (h[t] == ""){ //t位置空 则需查找的单词不在表里
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
//            s = s.substr(0, s.length() - 1); //去除标点
//        }
//        for (int i = 0; i < s.length(); i++) { //全部小写
//            if (s[i] >= 'A' && s[i] <= 'Z') {
//                s[i] = s[i] + 32;
//            }
//        }
//        Find(s);
//    }
//    in2.close();
//    cout << "共有" << total << "个错误" << endl;
    wordCheck check1;
    check1.buildHashmap();
    check1.findWrongwords();

    return 0;
}