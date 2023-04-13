//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
using namespace std;
//函数是求阶乘
int val(int n){//形参是隐式定义的
    int sum=1;
    while (n){
        sum*=n--;
    }
    return sum;
}
int main(){
    int n=0;
    cin>>n;//增加交互功能求指定阶乘
    int sum= val(n);
    cout<<sum;
    return 0;
}