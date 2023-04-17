//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
/*
 * CPP是在C语言的基础上进行设计的大部分的接口或着库函数都支持的C语言风格
 * 而不是都支持CPP所以经常要使用C语言的方式去调用
 * C语言风格的字符串是以字符数组的形式进行存储的末尾以'\0'为结束标志
 */
int main(){
    char name[11];
    memset(name,0, sizeof(name));//初始化C语言字符串
    for (int i = 0; i < 11; ++i) {
        cout<<(int )name[i]<<endl;
    }

    return 0;
}