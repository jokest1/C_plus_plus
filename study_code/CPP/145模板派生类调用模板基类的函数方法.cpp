//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 想在派生模板中定义基类的命名一样,派生类也无法直接调用基类的函数
 */
template<class T>
class test{
public:
    void print(){
        cout<<"基类print()"<<endl;
    }
};
template<class T>
class test1:public test<T>{
public:
    void print1(){
//        this->print();//这里无法找到这个函数需要使用this->;
        cout<<"派生类类print()"<<endl;
        using test<T>::print;
        print();//增加一个using基类函数的声明就可以调用了
    }
};