//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
/*
 * 引用的数据类型必须相同
 * 引用必须初始化
 */
int main(){
//    引用类型的语法:相同数据类型 引用变量名=被引用的变量;
    int a=8;
    int& ra=a;
//    引用的地址就是原数据的地址
    cout<<"&a"<<&a<<" a"<<a<<endl;
    cout<<"&ra"<<&ra<<" ra"<<ra<<endl;
    ra=10;
    cout<<"&a"<<&a<<" a"<<a<<endl;
    cout<<"&ra"<<&ra<<" ra"<<ra<<endl;
    return 0;
}