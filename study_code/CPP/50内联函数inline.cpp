//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
/*
 * 像这个max函数内容十分简短而且功能简单,但是每次调用都会开辟栈空间进行用
 * 为了提升效率使用inline关键字使得函数称为内联函数之后,可以直接在调用的地方进行内嵌而不产生调用
 * 如果被调函数代码复杂或着代码量大会使用大量内存,而且是否内嵌由编译器决定
 */
inline  int max(int a,int b){
    if(a>=b)return a;
    return b;
}

int main(){
    int a=10;
    int b=11;
//    inline函数直接内嵌入代码
//    max(a,b);
//    {
//        if(a>=b)return a;
//          return b;
//    }
    return 0;
}