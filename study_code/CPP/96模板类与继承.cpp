//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"
/*
 * 1.模板类继承普通类
 * 2.普通类继承模板类
 * 3.普通类继承模板类的实例化
 * 4.模板类继承模板类
 * 5.模板类继承模板参数的基类
 */
//1.普通类
class AA;
//2.模板类
template<class T1,class T2>
class BB{
public:
    T1 m_a;
    T2 m_b;
    BB(T1 mA, T2 mB) : m_a(mA), m_b(mB) {}
};

class AA:public BB<int,int>{
//普通类继承实例化模板类
public:
    int i;
    AA(int mA, int mB, int i) : BB(mA, mB), i(i) {}
};

template<class T1,class T2>
class CC:public BB<T1,T2>{
//普通类继承模板类
public:
    int j;
    CC(T1 mA, T2 mB, int j) : BB<T1,T2>(mA, mB), j(j) {}
};

class EE{
public:
    int i;

    EE(int i) : i(i) {}
};
template<class T1,class T2>
class DD:public EE{
//模板类继承普通类
public:
    T1 m_t1;
    T2 m_t2;
    DD(int i, T1 mT1, T2 mT2) : EE(i), m_t1(mT1), m_t2(mT2) {}
};

template<class T1, class T2>
class FF:public BB<T1,T2>{
//    模板类继承模板类
public:
    T1 m;
    T2 n;

    FF(T1 mA, T2 mB, T1 m, T2 n) : BB<T1,T2>(mA, mB), m(m), n(n) {}
};

template<class T>
class GG:public T{
public:
    int g;

    GG(int g) : g(g),T() {}
};

int main(){

    return 0;
}