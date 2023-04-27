//
// Created by 36302 on 2023/4/24.
//
/*
 * 在泛型基类中通过typedef的新名字在派生类中想要使用就需要在定义前加入typename
 */
template<class T>
class test{
public:
    typedef int INT;
};
template<class T>
class test1:public test<T>{
public:
//    test<T>::INT i;//无法使用基类的typedef名字
    typename test<T>::INT i=10;//使用了typename前置就可以定义了
};
