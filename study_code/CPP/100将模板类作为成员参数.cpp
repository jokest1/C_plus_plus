//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"
/*
 * 通过将模板类作为模板的模板形参实现数据结构的多态
 */
template<class T,int len>
class LinkedList{
public:
    void add(){cout<<"链表增加"<<endl;}
    void rome(){cout<<"链表删除"<<endl;}
    void get(){cout<<"链表查询"<<endl;}
};

template<class T, int len>
class ArrayList{
public:
    void add(){cout<<"数组增加"<<endl;}
    void rome(){cout<<"数组删除"<<endl;}
    void get(){cout<<"数组查询"<<endl;}
};

template<template<class, int> class List,class T,int len>
        class LineList{
        public:
            List<T,len> list;
            void add(){cout<<"增加:";list.add();}
            void rome(){cout<<"删除:";list.rome();}
            void get(){cout<<"查询:";list.get();}
        };
int main(){
    LineList<ArrayList,int,12> ll;
    ll.add();
    ll.rome();
    ll.get();
    return 0;
}