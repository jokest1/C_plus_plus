//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
/*
 * 当创建的许多类中有很多公共部分的函数和变量就可以将公共部分抽取出来
 * 继承是直接在派生类内包含一个基类的内容
 */
using namespace std;
class A{
public:
    int a;
};
class B:public A{
public:
    int b;
};

int main(){
    B bb;
    bb.b=20;
    bb.a=10;
//    bb中a和b的地址就差4个字节表明a和b是连续地址存放的
    cout<<"&aa.a:"<<&bb.a<<"\t&bb.b"<<&bb.b<<endl;

    return 0;
}