//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
using namespace std;
/*
 * 函数的定义和声明可以分开来写但是定义只能定义一次声明可以多次
 * 函数的返回值和形参类型要定义和声明要一致
 * 函数的返回值类型要与返回的值的类型一致
 * 实现函数并不关心返回的话可以写为void,不需要传参可以不写
 */
int max(int a,int b);
int main(){
    int a=10;
    int b=11;
    int sum;
    sum = max(a, b);
    cout<<sum;
    return 0;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}