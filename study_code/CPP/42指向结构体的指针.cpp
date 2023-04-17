//
// Created by 36302 on 2023/4/14.
//
#include <iostream>
/*
 * 结构体的指针指向结构体内存的首地址
 * 通过结构体指针可以用更少的内存消耗管理较大的数据类型
 */
using namespace std;
typedef struct Node{
    int no;
    char name[10];
}Node;

int main(){
    Node * p;
    p=new Node();
    cout<<"no:"<<p->no<<" name:"<<p->name<<endl;
    return 0;
}