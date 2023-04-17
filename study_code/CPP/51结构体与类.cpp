//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;

struct node{
    int i;
    int j;
    int k;
};
void initNode(node* n,int i,int j, int k){
    n->i=i;
    n->j=j;
    n->k=k;
}

struct node1{
    int ii;
    int jj;
    int kk;
    void initNode(int i,int j, int k){
        ii=i;jj=j;kk=k;
    }
};
int main(){
    node* p=new node;
    //结构体和结构体初识函数使分开的,而且需要传入要被初始化的结构体地址才可以完成初始化
    initNode(p,1,2,3);
    cout<<"p.i:"<<p->i<<" p.j:"<<p->j<<" p.k:"<<p->k<<endl;
    //将结构体和结构体相关的函数打包在一起,通过结构体变量才能调用结构体相关的方法
    node1*q=new node1;
    q->initNode(4,5,6);
    cout<<"q.i:"<<q->ii<<" q.j:"<<q->jj<<" p.k:"<<q->kk<<endl;
    return 0;
}