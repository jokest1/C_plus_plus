//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"

template<class T1,class T2>
class AAA{//定义了一个模板类,包含两个模板参数T1T2
public:
//    用模板参数定义了成员变量和构造函数
    T1 m_a;
    T2 m_b;
    AAA(T1 mA, T2 mB) : m_a(mA), m_b(mB) {}
//    创建了成员方法show()
    void show();
//    成员内部模板类,模板参数为T包含一个模板成员变量和一个成员函数show()
    template<typename T>
    class BBB{
    public:
        T m_aa;
        void show();
    };
//    实例化成员模板类并传递string为模板参数
    BBB<string> bb;
//    定义一个成员模板函数模板show(T)参数为T
    template<typename T>
    void show(T tt);
};
//类外实现成员函数show(),写明模板头和作用域
template<class T1,class T2>
void AAA<T1,T2>::show(){
    cout<<"m_a"<<m_a<<" m_b"<<m_b<<endl;
}
//类外实现成员模板类的成员函数show(),写明两个模板头和两个作用域
template<class T1,class T2>
template<typename T>
void AAA<T1,T2>::BBB<T>::show() {
    cout<<"string:"<<m_aa<<endl;
}
//类外实现成员模板函数,写明两个模板头和作用域
template<class T1,class T2>
template<typename T>
void AAA<T1,T2>::show(T tt) {
    cout<<"tt="<<tt<<endl;
    cout<<"m_a"<<m_a<<" m_b"<<m_b<<endl;
    bb.show();
}
int main(){
    AAA<int ,string> a(10,"qwe");
    a.show();
    a.bb.m_aa="asd";
    a.bb.show();
    a.show("zxc");
    return 0;
}