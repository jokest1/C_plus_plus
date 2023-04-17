//
// Created by 36302 on 2023/4/17.
//
#include <iostream>
/*
 * 匹配优先级:全局函数>特例化函数>泛型函数
 */
using namespace std;

template<typename T>
void Swap(T& t1,T& t2){
    cout<<"模板函数"<<endl;
}
void Swap(int & t1,int & t2){
    cout<<"全局函数"<<endl;
}
template<> void Swap(int& t1,int & t2){
    cout<<"模板的特例化"<<endl;
}
int main(){
    int i=10;
    int j=20;
    Swap<>(i,j);
}