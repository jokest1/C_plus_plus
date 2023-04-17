//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
/*
 * 派生类对基类的变量或者函数名重名时候不会发生覆盖仍会保留基类的同名变量
 * 在派生类内想使用基类的同名变量或者函数时候需要用作用域: 基类名::变量/函数名
 */
using namespace std;
class A{
public:
    int i;
    int j;

    A(int i, int j) : i(i), j(j) {}
    A(): i(0), j(0){}
    void func1(){
        cout<<"A::func1,"<<"i "<<i<<",j "<<j<<endl;
    }
};
class B:public A{
public:
    B(int i, int j) : i(i), j(j) {}

    int i;
    int j;
    void func1(){
        A::func1();
        cout<<"B::func1,"<<"i "<<i<<",j "<<j<<endl;
    }
};
int main(){
    cout<< sizeof(A)<<endl;
    cout<< sizeof(B)<<endl;
    A aa(1,2);
    B bb(3,4);
    aa.func1();
    bb.func1();
}