//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 虚函数是可以被重写的但是仍旧有着可以替代虚函数实现继承后重写的方法:
 * 1.public继承直接重写虚函数但是没法有更多的操作
 * 2.private继承然后在public写一个member之后去调用私有的虚函数,这个函数中间可以插入很多操作
 * 3.使用函数指针在实例化类的时候去重写需要的功能
 */
class base{
public:
    virtual void print()=0;
};
class derive1:public base{
public:
    void print() override{
        cout<<"虚函数被调用"<<endl;
    }
};
class derive2: private base{
public:
    void test(){
        cout<<"处理数据前"<<endl;
        print();
        cout<<"处理数据后"<<endl;
    }
private:
    void print() override{
        cout<<"虚函数被调用"<<endl;
    }
};
class derive3{
public:
    derive3(void (*pf)()) : pf(pf) {}
    void(*pf)();
};
int main(){
    derive1 d1;
    derive2 d2;
    derive3 d3([](){
        cout<<"重写虚函数"<<endl;
    });
    d1.print();
    d2.test();
    d3.pf();
    return 0;
}