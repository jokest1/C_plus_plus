//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;
/*
 * decltype会推断表达式的运行结果但是并不执行表达式
 * 推导规则:
 *      如果没有用括号起来的标识符,则类型与该标识符的类型相同，包括const等限定符
 *      表达式是一个函数调用，则推断的类型与函数的返回值类型相同
 *      是一个左值（能取地址）(要排除第一种情况)、或者用括号括起来的标识符，那么推断的类型是表达式的引用
 */
int main(){
    decltype ((1+2)) i=10;//计算表达式1+2的类型为int
    cout<< typeid(i).name()<<endl;
    return 0;
}