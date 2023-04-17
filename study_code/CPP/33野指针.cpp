//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * 野指针是指指向不明确地址
 * 指向的对空间已经被释放
 * 对野指针的解引用会引发不确定的行为,严重的会使程序崩溃
 */
int main(){
    int* p;             //p没有初始化指向的是一个不确定的地址
//    cout<<*p<<endl;     //*p会引发不确定的行为
    return 0;
}