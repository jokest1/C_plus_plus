//
// Created by 36302 on 2023/4/16.
//
#include <iostream>

using namespace std;
/*
 * 基类和派生类,构造派生类先构造基类后构造派生类,析构时候则从派生类开始析构然后是基类
 * 访问权限仅仅是语法上的限制
 * 派生类只会申请一次空间
 */
class A{
public:
    A(){
        cout<<"A的无参构造"<<endl;
    }

    virtual ~A() {
        cout<<"A的析构函数"<<endl;
    }
};
class B:public A{
public:
    B(){
        cout<<"B的无参构造"<<endl;
    }

    virtual ~B() {
        cout<<"B的析构函数"<<endl;
    }
};

int main(){
    B bb;
    return 0;
}