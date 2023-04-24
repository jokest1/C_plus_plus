//
// Created by 36302 on 2023/4/18.
//
#include "test_base.h"

template<class T1, class T2>
struct Pair{
    T1 first;
    T2 second;
    Pair() {
        cout<<"调用了无参构造"<<endl;
    }
    Pair(const T1& first, const T2& second) {
        cout<<"调用了带参构造"<<endl;
    }
    Pair(const Pair<T1,T2>& p){
        cout<<"调用了拷贝构造"<<endl;
    }
    void swap(Pair<T1,T2>& p){
        cout<<"调用了交换函数"<<endl;
    }
};
template<class T1, class T2>
Pair<T1,T2> make_pair(const T1 &first,const T2 &second){
    return Pair<T1,T2>(first,second);
}
int main(){
    Pair<int,string>pp1;
    Pair<int,string>pp2(10,"20");
    auto pp3= make_pair<int,string>(10,"20");
    Pair<int,string> pp4(pp2);
}