//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"
/*
 * 模板类的匹配优先级:全特化匹配>偏特化匹配>模板类
 */
template<class T1, class T2>
class AA{
public:
    T1 m_a;
    T2 m_b;
    AA(T1 mA, T2 mB) : m_a(mA), m_b(mB) {
        cout<<"模板类构造函数"<<endl;
    }
    void show(){
        cout<<"模板类型AA<T1,T2>"<<endl;
    }
};

template<class T1>
class AA<T1,string>{
public:
    T1 m_a;
    string m_b;
    AA(T1 mA, string mB) : m_a(mA), m_b(mB) {
        cout<<"偏特化类构造函数"<<endl;
    }
    void show(){
        cout<<"偏特化类型AA<T1,string>"<<endl;
    }
};
template<>
class AA<int,string>{
public:
    int m_a;
    string m_b;
    AA(int mA, string mB) : m_a(mA), m_b(mB) {
        cout<<"全特化类构造函数"<<endl;
    }
    void show(){
        cout<<"全特化类型AA<int,string>"<<endl;
    }
};
int main(){
    AA<int,string> a1(10,"10");
    a1.show();
    AA<char,string> a2(10,"10");
    a2.show();
    AA<int,double> a3(10,0.0);
    a3.show();
    return 0;
}