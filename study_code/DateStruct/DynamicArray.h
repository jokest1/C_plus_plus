//
// Created by 36302 on 2023/4/11.
//
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define ELEMENT_NOT_EXISTS -1
#define DEFAULT_CAPACITY 10
typedef int E;
typedef struct DynamicArray {
    E* data;
    int size;
    int capacity;
}DynamicArray;
void createArray(int capacity,DynamicArray* dA);//构造函数
void rangeCheckIndex(int index,const DynamicArray* dA);//检查索引
void rangeCheckCapacity(DynamicArray* dA);//检查容量
int size(const DynamicArray* dA);         //返回元素总量
void clear(DynamicArray* dA);       //清空元素
bool empty(const DynamicArray* dA);       //判断是否为空
void add(int index,E element,DynamicArray* dA);//添加元素
void push_back(E element,DynamicArray* dA);//尾添加
E erase(int index,DynamicArray* dA);     //擦除元素
E pop_back(DynamicArray* dA);           //尾删除
E get(int index,const DynamicArray* dA);       //取元素
bool contains(E element,const DynamicArray* dA);//判断包含
int indexOf(E element,const DynamicArray* dA); //取元素索引
void set(int index,E element,DynamicArray* dA);//修改索引位置元素

void createArray(int capacity,DynamicArray* dA) {
    int newCap=(capacity>DEFAULT_CAPACITY?capacity:DEFAULT_CAPACITY);
    dA->data=(E*) malloc(sizeof(E)*newCap);
    if(dA->data==NULL){
        exit(-1);
    }
    dA->capacity=newCap;
    dA->size=0;
}
void rangeCheckIndex(int index,const DynamicArray* dA){
    if(index<0||index>=dA->size){
        printf("index error\n");
        exit(-1);
    }
}
void rangeCheckCapacity(DynamicArray* dA){
    if(dA->size>=dA->capacity){
        int newCap=(dA->capacity<<1);
        E* temp=(E*) malloc(sizeof(E)*newCap);
        if(temp==NULL){
            free(dA->data);
            exit(-1);
        }
        for (int i = 0; i < dA->size; ++i) {
            temp[i]=dA->data[i];
        }
        free(dA->data);
        dA->data=temp;
        dA->capacity=newCap;
    }
}
int size(const DynamicArray* dA) {
    return dA->size;
}
void clear(DynamicArray* dA) {
    dA->size=0;
}
bool empty(const DynamicArray* dA) {
    return dA->size==0;
}
void add(int index,E element,DynamicArray* dA) {
    if(index!=dA->size){
        rangeCheckIndex(index,dA);
    }
    rangeCheckCapacity(dA);
    for (int i = dA->size; i >index ; --i) {
        dA->data[i]=dA->data[i-1];
    }
    dA->data[index]=element;
    ++dA->size;
}
void push_back(E element,DynamicArray* dA) {
    add(dA->size,element,dA);
}
E erase(int index,DynamicArray* dA) {
    rangeCheckIndex(index,dA);
    E old=dA->data[index];
    --dA->size;
    for (int i = index; i < dA->size; ++i) {
        dA->data[i]=dA->data[i+1];
    }
    return old;
}
E pop_back(DynamicArray* dA) {
    return erase(dA->size-1,dA);
}
E get(int index,const DynamicArray* dA) {
    return dA->data[index];
}
bool contains(E element,const DynamicArray* dA) {
    return ELEMENT_NOT_EXISTS!= indexOf(element,dA);
}
int indexOf(E element,const DynamicArray* dA) {
    for (int i = 0; i < dA->size; ++i) {
        if(dA->data[i]==element){
            return i;
        }
    }
    return ELEMENT_NOT_EXISTS;
}
void set(int index,E element,DynamicArray* dA) {
    rangeCheckIndex(index,dA);
    dA->data[index]=element;
}