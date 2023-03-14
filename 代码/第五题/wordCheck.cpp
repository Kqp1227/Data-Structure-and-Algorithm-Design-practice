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
    int t = (x[0] - 65) * 10000 + (x[m] - 65) * 100 + x[l - 1] - 65;   //ȡֵ����
    return t % maxn;
}

void wordCheck::Insert(string x) {
    int t = Hash(x);
    while (h[t] != "" && h[t] != x) {
        t++; //��λ���е�����λ��
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
    }//ֱ�Ӷ�λλ��t
    if (h[t] == "") { //tλ�ÿ� ������ҵĵ��ʲ��ڱ���
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
            s = s.substr(0, s.length() - 1); //ȥ�����
        }
        for (int i = 0; i < s.length(); i++) { //ȫ��Сд
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
            }
        }
        if (Find(s) == false) {
            total++;
            cout << s << " ���󣬿��޸�Ϊ��";
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
    cout << "����" << total << "������" << endl;
}


wordCheck::~wordCheck() {
    delete h;
}

