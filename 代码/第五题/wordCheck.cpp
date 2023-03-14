//
// Created by 13439 on 2022/6/30.
//

#include "wordCheck.h"

wordCheck::wordCheck() {
    h = new string[maxn + 1];
}

int wordCheck::Hash(string x) {
    int l = x.length();
    int m = l / 2;
    int t = (x[0] - 65) * 10000 + (x[m] - 65) * 100 + x[l - 1] - 65;   //取值方法
    return t % maxn;
}

void wordCheck::Insert(string x) {
    int t = Hash(x);
    while (h[t] != "" && h[t] != x) {
        t++; //该位置有单词则换位置
        if (t == maxn)
            t = 0;
    }
    h[t] = x;
}

bool wordCheck::Find(string x) {
    int t = Hash(x);
    int k = t;
    string right;

    while (h[t] != "" && h[t] != x) {
        t++;
        if (t == maxn)
            t = 0;
    }//直接定位位置t
    if (h[t] == "") { //t位置空 则需查找的单词不在表里
//        cout << ", can change to: " << right << endl;

        return false;
    }
    return true;
}

int wordCheck::repeatError(string wrongWord) {
    int tmp;
    for (int i = 0; i < wrongWord.length() - 1; i++) {
        if (wrongWord[i] == wrongWord[i + 1]) {
            wrongWord.erase(i, 1);
            tmp = i + 1;
        }
    }
    if (Find(wrongWord)) {
        cout << wrongWord;
        return 1;
    } else {
        for (int j = 0; j < 26; j++) {
            string tmpWrong = wrongWord;
            tmpWrong.insert(tmp, charBox[j]);
            if (Find(tmpWrong)) {
                cout << tmpWrong;
                return 1;
            }
        }
    }
    return 0;

}

int wordCheck::swapError(string wrongWord) {
    for (int i = 0; i < wrongWord.length() - 1; i++) {
        string tmpWrong = wrongWord;
        char tmp = tmpWrong[i];
        tmpWrong[i] = tmpWrong[i + 1];
        tmpWrong[i + 1] = tmp;
        if (Find(tmpWrong)) {
            cout << tmpWrong;
            return 1;
        }
    }
    return 0;
}

int wordCheck::lossError(string wrongWord) {
    for (int i = 0; i < wrongWord.length(); i++) {
        string tmpWrong = wrongWord;
        string get = tmpWrong.substr(i, 1);
        tmpWrong.insert(i, get);
        if (Find(tmpWrong)) {
            cout << tmpWrong;
            return 1;
        } else {
            for (int j = 0; j < 26; j++) {
                string tmpWrong = wrongWord;
                tmpWrong.insert(i, charBox[j]);
                if (Find(tmpWrong)) {
                    cout << tmpWrong;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void wordCheck::buildHashmap() {
    string s;
    ifstream in("dic.txt");
    while (getline(in, s)) {
        Insert(s);
    }
    in.close();
}

void wordCheck::findWrongwords() {
    string s;
    ifstream in2("doc.txt");
    while (in2 >> s) {
        if (s[s.length() - 1] == ',' || s[s.length() - 1] == ':' || s[s.length() - 1] == '.' ||
            s[s.length() - 1] == '?') {
            s = s.substr(0, s.length() - 1); //去除标点
        }
        for (int i = 0; i < s.length(); i++) { //全部小写
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
            }
        }
        if (Find(s) == false) {
            total++;
            cout << s << " 有误，可修改为：";
            int tmp = 0;
            tmp += repeatError(s);
            if (tmp == 0) {
                tmp += swapError(s);
            }
            if (tmp == 0) {
                tmp += lossError(s);
            }
            cout << endl;
        }

    }
    in2.close();
    cout << "共有" << total << "个错误" << endl;
}


wordCheck::~wordCheck() {
    delete h;
}

