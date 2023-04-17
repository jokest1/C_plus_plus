//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;
/*
 * 允许使用auto占位返回值类型,之后使用->类型来指出后置返回值类型
 */
auto func(int i,int j)->int{
    return i+j;
}
int main(){

    int i=10;
    int j=20;
    int sum=func(i,j);
    cout<<sum<<endl;
}
