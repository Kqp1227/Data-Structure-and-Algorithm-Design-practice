//
// Created by 13439 on 2022/6/30.
//

#ifndef DS_T_Q5_WORDCHECK_H
#define DS_T_Q5_WORDCHECK_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class wordCheck {
public:
    const int maxn = 109584;
    wordCheck();
    ~wordCheck();
    int Hash(string x);
    void Insert(string x);
    bool Find(string x);
    void buildHashmap();
    void findWrongwords();
private:
    int total = 0;
    string* h;
    string charBox[26] = {"a","b","c","d","e","f","g","h","i",
                          "j","k","l","m","n","o","p","q",
                          "r","s","t","u","v","w","x","y","z" };
    int repeatError(string wrongWord);
    int swapError(string wrongWord);
    int lossError(string wrongWord);

};


#endif //DS_T_Q5_WORDCHECK_H
