//
// Created by Kqp1227 on 2022/6/30.
//

#include "HuffmanCode.h"
HuffmanCode::HuffmanCode(int a) {
    n = a;
    ht = new Node[2*n];
    hcode = new Hcode[n];
    for (int i = 0; i<n; i++) {
        cin >> ht[i].data;
    }
    for (int i = 0; i<n; i++) {
        cin >> ht[i].weight;
    }
}

void HuffmanCode::create_ht(Node ht[], int n)//根据原节点的权值构造huffman树
{
    int min1, min2;
    int left_node, right_node;

    //初始化节点
    //叶子节点 - 需要进行编码的字母
    for (int i = 0; i < 2 * n - 1; i++) {
        ht[i].parent = -1;
        ht[i].left_child = -1;
        ht[i].right_child = -1;
    }

    //其余节点 - 建立完整huffman树
    for (int i = n; i < 2 * n - 1; i++)
    {
        min1 = min2 = Max_weight;
        left_node = right_node = -1;//最小权重两个节点的位置
        for (int k = 0; k < i; k++)
        {
            //遍历 找到最小权重的两个节点 权重分别记录在min1和min2中
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) { //比较权重
                    min2 = min1;
                    right_node = left_node;
                    left_node = k; //最小权重的节点记录在left_node里
                    min1 = ht[k].weight; //更新min值
                }
                else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    right_node = k; //第二小权重的节点记录在right_node里
                }
            }
        }
        //cout << "当前选中" << ht[left_node].data << "&" << ht[right_node].data << endl;
        ht[left_node].parent = i;
        ht[right_node].parent = i;
        ht[i].weight = ht[left_node].weight + ht[right_node].weight;
        ht[i].left_child = left_node;
        ht[i].right_child = right_node;
        //cout << "生成新节点权重：" << ht[i].weight << endl;
    }
}

void HuffmanCode::create_hcode(Node ht[], Hcode hcode[], int n)//将每个字符转换为相应的huffman编码存入编码数组中
{
    Hcode hc;//临时的结构体变量
    for (int i = 0; i < n; i++)
    {
        hc.start = n;
        int c = i;
        int f = ht[i].parent;
        //由于这里是从叶子节点往根节点走，而实际的Huffman编码为从根节点到叶子结点
        //所以下面的start为从n开始递减，输出是按照start到n正序输出
        while (f != -1) //循环直到树根
        {
            if (ht[f].left_child == c) {//判断是否为父节点的左孩子节点
                hc.code[hc.start--] = '0';
            }
            else {
                hc.code[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;//start指向huffman编码最开始的字符
        hcode[i] = hc;//将当前字符的huffman编码存入编码数组中
    }
}

void HuffmanCode::create() {
    create_ht(ht, n);
    create_hcode(ht,hcode,n);
}

void HuffmanCode::encoding(char* arr)//对传入字符串进行编码
{
    //create_hcode函数已经将字符分别转换为0-1编码
    //直接寻找对应的并输出即可
    Node temp[100];
    for (int i = 0; i<strlen(arr); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ht[j].data == arr[i])
            {
                for (int k = hcode[j].start; k <= n; k++)
                {
                    cout << hcode[j].code[k];
                }
            }
        }
    }
    cout << endl;
}

void HuffmanCode::decoding(char* arr)//对传入编码进行解码
{
    int i = 0;
    while (i < strlen(arr))
    {
        int temp = 2 * n - 2;
        //从根节点开始遍历 0则进入左子树 1则进入右子树
        //遍历到叶子节点时输出该叶子节点代表的字符
        while ((ht[temp].left_child != -1) && (ht[temp].right_child != -1))//判断哈夫曼树是否走到了叶子节点
        {
            if (arr[i] == '0')
            {
                temp = ht[temp].left_child;
            }
            else if (arr[i] == '1')
            {
                temp = ht[temp].right_child;
            }
            i++;
        }
        cout << ht[temp].data;
    }
    cout << endl;
}

HuffmanCode::~HuffmanCode() {
    delete ht;
    delete hcode;
}