//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
/*
 * 函数名相同但是形参类型或数量不同可以构成函数的重载
 * 函数重载时候尽量不要对以形参数量进行重载的函数进行设置默认值
 * 函数重载如果不存在完美匹配而是存在多个隐式转换的匹配则报错
 * const不能作为重载的特征
 * 返回值不能作为重载的特征
 */
void func(int i);
void func(short s);
void func(long l);
void func(double d);
int main(){


    return 0;
}
void func(int i){

}
void func(short s){

}
void func(long l){

}
void func(double d){

}