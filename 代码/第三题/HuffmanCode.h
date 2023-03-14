//
// Created by Kqp1227 on 2022/6/30.
//

#ifndef UNTITLED3_HUFFMANCODE_H
#define UNTITLED3_HUFFMANCODE_H
#pragma once
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
#define Max_weight 32767

struct Node {//原节点结构体
    int weight;
    int parent;
    int left_child;
    int right_child;
    char data;
};

struct Hcode {//编码结构体
    char code[50];//存储哈夫曼编码
    int start;
};

class HuffmanCode {
public:
    HuffmanCode(int a);
    ~HuffmanCode();
    void create();
    void encoding(char* arr);
    void decoding(char* arr);

private:
    int n = 0;
    Node* ht;
    Hcode* hcode;
    void create_ht(Node ht[], int n);
    void create_hcode(Node ht[], Hcode hcode[], int n);
};


#endif //UNTITLED3_HUFFMANCODE_H

