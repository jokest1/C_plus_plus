//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"

template<class T1,class T2>
class AAA{
public:
    T1 name;
    T2 no;
    AAA(T1 name, T2 no) : name(name), no(no) {}
    void func(){
        cout<<name<<":"<<no;
    }
};
//接收AAA<string,int>类型的成员函数,只能支持这一种形式
AAA<string,int> print(AAA<string,int>& temp){
    cout<<"AAA<string,int>&()"<<endl;
    temp.func();
    return temp;
}
//在没有上方成员函数时候这个泛型模板可以调用任何含有func()成员函数的类类型
template<class T>
T print(T& temp){
    cout<<"T&()"<<endl;
    temp.func();
    return temp;
}
int main(){
    AAA<string,int> aa("wang",11);
    print(aa);
    return 0;
}

