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

void HuffmanCode::create_ht(Node ht[], int n)//����ԭ�ڵ��Ȩֵ����huffman��
{
    int min1, min2;
    int left_node, right_node;

    //��ʼ���ڵ�
    //Ҷ�ӽڵ� - ��Ҫ���б������ĸ
    for (int i = 0; i < 2 * n - 1; i++) {
        ht[i].parent = -1;
        ht[i].left_child = -1;
        ht[i].right_child = -1;
    }

    //����ڵ� - ��������huffman��
    for (int i = n; i < 2 * n - 1; i++)
    {
        min1 = min2 = Max_weight;
        left_node = right_node = -1;//��СȨ�������ڵ��λ��
        for (int k = 0; k < i; k++)
        {
            //���� �ҵ���СȨ�ص������ڵ� Ȩ�طֱ��¼��min1��min2��
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) { //�Ƚ�Ȩ��
                    min2 = min1;
                    right_node = left_node;
                    left_node = k; //��СȨ�صĽڵ��¼��left_node��
                    min1 = ht[k].weight; //����minֵ
                }
                else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    right_node = k; //�ڶ�СȨ�صĽڵ��¼��right_node��
                }
            }
        }
        //cout << "��ǰѡ��" << ht[left_node].data << "&" << ht[right_node].data << endl;
        ht[left_node].parent = i;
        ht[right_node].parent = i;
        ht[i].weight = ht[left_node].weight + ht[right_node].weight;
        ht[i].left_child = left_node;
        ht[i].right_child = right_node;
        //cout << "�����½ڵ�Ȩ�أ�" << ht[i].weight << endl;
    }
}

void HuffmanCode::create_hcode(Node ht[], Hcode hcode[], int n)//��ÿ���ַ�ת��Ϊ��Ӧ��huffman����������������
{
    Hcode hc;//��ʱ�Ľṹ�����
    for (int i = 0; i < n; i++)
    {
        hc.start = n;
        int c = i;
        int f = ht[i].parent;
        //���������Ǵ�Ҷ�ӽڵ������ڵ��ߣ���ʵ�ʵ�Huffman����Ϊ�Ӹ��ڵ㵽Ҷ�ӽ��
        //���������startΪ��n��ʼ�ݼ�������ǰ���start��n�������
        while (f != -1) //ѭ��ֱ������
        {
            if (ht[f].left_child == c) {//�ж��Ƿ�Ϊ���ڵ�����ӽڵ�
                hc.code[hc.start--] = '0';
            }
            else {
                hc.code[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;//startָ��huffman�����ʼ���ַ�
        hcode[i] = hc;//����ǰ�ַ���huffman����������������
    }
}

void HuffmanCode::create() {
    create_ht(ht, n);
    create_hcode(ht,hcode,n);
}

void HuffmanCode::encoding(char* arr)//�Դ����ַ������б���
{
    //create_hcode�����Ѿ����ַ��ֱ�ת��Ϊ0-1����
    //ֱ��Ѱ�Ҷ�Ӧ�Ĳ��������
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

void HuffmanCode::decoding(char* arr)//�Դ��������н���
{
    int i = 0;
    while (i < strlen(arr))
    {
        int temp = 2 * n - 2;
        //�Ӹ��ڵ㿪ʼ���� 0����������� 1�����������
        //������Ҷ�ӽڵ�ʱ�����Ҷ�ӽڵ������ַ�
        while ((ht[temp].left_child != -1) && (ht[temp].right_child != -1))//�жϹ��������Ƿ��ߵ���Ҷ�ӽڵ�
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