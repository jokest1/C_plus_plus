//
// Created by 36302 on 2023/4/21.
//
#include "test_base.h"

void show(const int& no){
    cout<<"第"<<no<<"号\n";
}
class showno{
public:
    void operator()(const int& no){
        cout<<"第"<<no<<"号\n";
    }
};
namespace lz
{

//通过将形参设置为两个迭代器,并且传入对数据的处理方法
void foreach(const vector<int>::iterator begin,vector<int>::iterator  end,void (*pfun)(const int& no)){
    auto it=begin;
    while (it!=end){
        pfun(*it);
        ++it;
    }
}
//定义成仿函数类

void foreach(const vector<int>::iterator begin,vector<int>::iterator  end,showno swn){
    auto it=begin;
    while (it!=end){
        swn(*it);
        ++it;
    }
}
}
//将foreach改写为泛型函数
template<class T1,class T2>
void foreach(const T1& begin,const T1& end,T2 pfun){
    auto it=begin;
    while (it!=end){
        pfun(*it);
        ++it;
    }
}
//通过类来传递更多的信息,然后重载()运算符来进行仿函数调用
template<class T>
class equalE{
    T one;
public:
    equalE(T one) : one(one) {}
public:
    bool operator()(const T& two){
        return one==two;
    }
};
template<class T1,class T2>
bool findif(const T1& begin,const T1& end,T2 pfun){
    auto it=begin;
    while (it!=end){
        if (pfun(*it++)){
            cout<<"存在\n";
            return true;
        }
    }
    cout<<"不存在\n";
    return false;
}
namespace test{
    /*
     * 类使用之前必须要先定义而不是声明声明也并不知道要占用多少内存空间
     */
    class name{
        int i;
    public:
        name(int i) : i(i) {}
        name() {}
        void operator()(){
            cout<<i<<"\n";
        }
    };
    void test(name na){
        na();
    }
}
int main(){
    list<int> vv{23,56,75,10,35,14,52};
//    foreach(vv.begin(),vv.end(),show);
//    cout<<"----------"<<endl;
//    foreach(vv.begin(),vv.end(),showno());
    findif(vv.begin(),vv.end(),equalE<int>(13));
    return 0;
}