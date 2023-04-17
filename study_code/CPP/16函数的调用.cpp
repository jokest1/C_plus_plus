//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
/*
 * 被调用的函数一定要在main函数之前定义
 * 被调函数的形参一定要匹配
 * 被调函数可以充当一个返回值类型的数据参与运算
 * 调用函数独占一行成为语句
 * 如有返回值但不关心返回值是什么也可以直接不处理
 */
using namespace std;

int max(int a,int b);
int main(){
    int a=10;
    int b=11;
    int sum;
    sum = max(a, b);
//    sun=max("av",10)//类型不匹配
  max(10,11);
    cout<<sum;
    return 0;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}