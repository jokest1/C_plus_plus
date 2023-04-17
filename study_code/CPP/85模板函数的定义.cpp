//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;

template<typename T>
void Swap(T& t1,T& t2){
    T temp=t1;
    t1 =t2;
    t2=temp;
}
int main(){
    int i=10;
    int j=20;
    cout<<"i:"<<i<<" j:"<<j<<endl;
    Swap(i,j);//运行时自动推导T为int
    cout<<"i:"<<i<<" j:"<<j<<endl;
    char c1='a';
    char c2='b';
    cout<<"c1:"<<c1<<" c2:"<<c2<<endl;
    Swap(c1,c2);
    cout<<"c1:"<<c1<<" c2:"<<c2<<endl;
    return 0;
}