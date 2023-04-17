//
// Created by 36302 on 2023/4/16.
//
#include <iostream>

using namespace std;
/*
 * 在派生类中重定义虚函数时，函数特征要相同。
 * 当在基类中定义了虚函数时，如果派生类没有重定义该函数，那么将使用基类的虚函数
 * 在派生类中重定义了虚函数的情况下，如果想使用基类的虚函数，可以加类名和域解析符。
 * 如果要在派生类中重新定义基类的函数，则将它设置为虚函数；否则，不要设置为虚函数
 */
class A{
public:
    virtual void show(){
        cout<<"A::show()"<<endl;
    }
};
class B:public A{
public:
    void show(){
        cout<<"B::show()"<<endl;
    }
};
class C:public A{
public:
    void show(){
        cout<<"C::show()"<<endl;
    }
};
int main(){
//    在基类指向派生类时候全都调用了A的show()方法
//    将show()方法定义为virtual,调用show()方法会根据具体的类型调用对应的show()
    A* aa1=new A;
    aa1->show();
    A* aa2=new B;
    aa2->show();
    A* aa3=new C;
    aa3->show();
    return 0;
}