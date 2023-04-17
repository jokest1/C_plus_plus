//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
//1.为复杂名称的数据类型起别名方便记忆和阅读
//2.提高代码不同平台的兼容性,比如限制int的长度
int main(){
    typedef unsigned int uint;
    typedef unsigned long ulong;
    //这里将复杂的数据类型名简化
    typedef short int_16;
    typedef int int_32;
    //这里创建与平台无关的数据类型使代码兼容性提高
    return 0;
}