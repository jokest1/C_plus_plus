//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * CPP提供了在定义时候用括号内容初始化的方法
 */
int main(){
    int i=10;
    int j=(11);//也可以用等号链接
    int k(12);//初始化赋值可以提高效率
    cout<<"i:"<<i<<" j:"<<j<<" k"<<k<<endl;
    return 0;
}