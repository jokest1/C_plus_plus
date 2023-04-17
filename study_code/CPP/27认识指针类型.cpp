//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * C++的高性能在于她有指针类型,指针类型也就是存放数据的内存首地址
 * 数据是多个连续的内存空间存放数据,指针就是指向基类型的首地址的类型
 * 指针的大小固定64位为8字节32位为4字节
 * 因为是同一片内存地址空间所以通过指针也可以修改原变量
 */
int main(){
    int a=10;
    int *p=&a;

    cout<<(void*)p<<endl;
    cout<<(void *)&a<<endl;
    cout<<"sizeof(int*)"<< sizeof(p)<<endl;//证明指针的大小相同
    cout<<"sizeof(double*)"<< sizeof(double*)<<endl;//
    *p=30;//通过指针解引用的方式去修改内存空间的内容,间接修改指向的数据内容
    cout<<"a"<<a<<endl;
}