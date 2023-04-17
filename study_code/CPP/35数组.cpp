//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
int main(){
    /*
     * 数组是语言提供内置数据结构,通过一篇连续的内存地址空间存储相同类型的元素
     */
    int arr[10]={};//初始化全为0
    int arr1[10]={1,2,3};//部分初始化
    cout<< sizeof(arr)<<endl;//求出的是10个int的数据类型整体的大小
    return 0;
}