//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"
/*
 *模板函数的友元有三种写法:
 *      非模板友元：友元函数不是模板函数，而是利用模板类参数生成的函数。
 *      约束模板友元：模板类实例化时，每个实例化的类对应一个友元函数。
 *      非约束模板友元：模板类实例化时，如果实例化了n个类，也会实例化n个友元函数，每个实例化的类都拥有n个友元函数。
 */
//约束模板友元:
//      1.首先声明一个模板成员函数
//      2.在模板类内通过将形参写为类的模板化作为形参类型
template<typename T>
void func2(T &aa);

template<class T>
class AAA{
    T m_a;
public:
//    friend void func1(AAA<int>& aa);//非模板友元,并不是模板函数不支持特化
    friend void func2(AAA<T>& aa){
        cout<<"func2():"<<aa.m_a<<endl;
    }
    AAA(T mA) : m_a(mA) {}
};

//AAA<int> aa;
//void func1(AAA<int>& aa){
//    cout<<"func1():"<<aa.m_a<<endl;
//}

int main(){
    AAA<string> aa("zhang");
    func2(aa);
    return 0;
}