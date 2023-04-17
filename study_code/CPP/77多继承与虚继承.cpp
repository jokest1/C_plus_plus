//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
/*
 * B和C都继承了A而D继承了BC但是D内有两份A的内容会造成内存浪费且调用时候还要加入命名空间
 * 使用虚继承来解决内容重复,会加入一个虚指针指向一个虚表,虚指针是相对位置
 */
using namespace std;
class A{
public:
    int m=10;
};
class B:virtual public A{
public:

};
class C:virtual public A{

};
class D:public B,C{

};
int main(){
    cout<< sizeof(A)<<endl;
    cout<< sizeof(B)<<endl;
    cout<< sizeof(C)<<endl;
    cout<< sizeof(D)<<endl;
    cout<< sizeof(int*)<<endl;
    A a;
    B b;
    C c;
    D d;
    cout<<d.B::m<<endl;
    return 0;
}