//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * 算数运算符号要求两侧数据符合运算符的运算规则类型
 * 同时大空间变量和小空间变量类型进行运算时候会自动提升到大空间类型
 */
int main(){
    int a=5;
    int b=6;
    float c=8;
    double d=16;
    cout<<b/a<<endl;
//  int类型相除会舍弃小鼠部分
    cout<<c/a<<endl;
//    只要含有float或double参与运算都会保留小数部分
    cout<<d/c<<endl;
//
    cout<<d/0.0<<endl;
//    double除以folat或者double的0.0都会输出inf表示无穷大
//    cout<<5/0<<endl; //除数为零报错
    cout<<(float)a/b<<endl;//通过强制类型转换成为有float参与运算
    return 0;
}