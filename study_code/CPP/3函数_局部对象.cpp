//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
using namespace std;
int k=99;
void test(){
    int i=10;
    int j=20;
    cout<<&i<<"\t"<<j<<"\t"<<k<<"\n";
    //i输出10不是main的11,k输出99为全局变量
}
int main(){
    int i=11;
    test();
    cout<<&i;
    //i的值没有因为调用改变证明两个i不同
    return 0;
}