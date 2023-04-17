//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * 函数的递归是函数自己调用自己,将问题层层减少但是递归程序中必须要有结束条件
 */
int func(int x){        //这是一个递归函数
    if(x==0)return 0;   //递归函数的结束条件
    return x+ func(x-1);    //递归函数在函数体内调用了自己
}

int main(){
    cout<<func(10)<<endl;//求1到10的累加和
    return 0;
}