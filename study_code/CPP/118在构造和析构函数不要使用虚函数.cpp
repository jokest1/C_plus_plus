//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 不要在构造函数中使用虚函数成员,虚函数根据当前的this指针会发生不同的调用
 * 在派生和基类的构造函数中调用了虚函数,派生构造的时候会上跳到基类构造函数this发生了改变
 * 这个时候会调用基类的同名虚函数而不是想要的派生类的虚函数
 */
class baseTest{
private:
    int i;
    int j;
public:
    baseTest() {
        cout<<"调用了Base()"<<endl;
        testV();
    }
    virtual void testV(){
        cout<<"调用基类的虚函数"<<endl;
    }
};
class devirTest1:public baseTest{
public:
    devirTest1() {
        cout<<"调用了devirTest1()"<<endl;
        testV();
    }
    virtual void testV(){
        cout<<"调用派生类的虚函数"<<endl;
    }
};
int main(){
    cout<< sizeof(devirTest1)<<endl;
    delete(new devirTest1());
    return 0;
}