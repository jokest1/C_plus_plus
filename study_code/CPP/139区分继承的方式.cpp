//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 类在继承函数的时候有三种继承的方式: 纯虚函数 带有默认定义的虚函数 非虚函数
 * 纯虚函数不带任何实现定义部分为=0,不可以被实例化
 * 半虚函数带有默认的定义,重写后仍可以调用重写前
 * 非虚函数不可以被重写
 */
class base{
public:
    virtual void print1()=0;
    virtual void print2(){
        cout<<"带默认实现的虚函数"<<endl;
    }
    void print3(){
        cout<<"非虚函数"<<endl;
    }
};
class baseT:public base{
public:
    void print1() override{
        cout<<"派生类重写纯虚"<<endl;
    }
    void print2() override{
        cout<<"重写半虚函数并调用基类的函数"<<endl;
        base::print2();
    }
};
int main(){
    baseT bt;
    bt.print1();
    bt.print2();
    bt.print3();
    return 0;
}