//
// Created by 36302 on 2023/4/17.
//
#include <iostream>
/*
 * auto自动推导类型语法: auto 变量名=数据;
 * auto会根据数据类型自动定义数据类型
 * 定义时候必须初始化,不可以作为形参类型,不能定义数组,不能声明静态类型
 */
using namespace std;

int main(){
    int i=10;
    auto a=i;
//    auto的实际使用主要是避免复杂的变量声明
    return 0;
}
