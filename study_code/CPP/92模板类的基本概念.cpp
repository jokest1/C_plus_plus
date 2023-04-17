//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"
/*
 * 使用模板类编程
 *      在创建对象的时候，必须指明具体的数据类型
 *      使用类模板时，数据类型必须适应类模板中的代码
 *      类模板可以为通用数据类型指定缺省的数据类型
 *      模板类的成员函数可以在类外实现
 *      可以用new创建模板类对象
 *      在程序中，模板类的成员函数使用了才会创建
 */
template<class T>
class AA{
public:
    T m_a;
    T m_b;

    AA() {}
    AA(T mA, T mB) : m_a(mA), m_b(mB) {}

    T getMA() const {
        T a=2;
        return m_a+2;
    }
    T getMB()const;
};
//成员可以类外实现
template<class T>
T AA<T>::getMB() const {
    T b=3;
    return m_b+b;
}

int main(){
    AA<int> a1(10,20);
//    AA<string> s1("10","20");
    cout<<a1.getMA()<< endl;
    cout<<a1.getMB()<< endl;
//    cout<<s1.getMA()<< endl;//string类型T a=2;报错,数据类型必须适应类模板中的代码
    return 0;
}