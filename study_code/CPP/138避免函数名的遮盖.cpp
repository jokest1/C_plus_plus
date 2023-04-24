//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 尽量避免在继承基类的时候遮盖基类的已有的函数或者变量名
 * 遮盖后:1调用时候使用基类名::指出调用基类 2在派生类中使用using 基类::重复名指出
 */
class test{
public:
    void print(){
        cout<<"基类"<<endl;
    }
private:
};
class test1:public test{
public:
    void print(){
        test::print();
        cout<<"派生类"<<endl;
    }
};
int main(){
    test1 t1;
    t1.print();//名字发生了遮盖优先调用派生类
    t1.test::print();//名字发生了遮盖使用名字指出调用对象
    t1.print();
    return 0;
}