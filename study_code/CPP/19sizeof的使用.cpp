//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * sizeof不是函数是关键字
 */
int main(){
    cout<<"sizeof(int)"<<sizeof(int)<<endl;
    cout<<"sizeof(float)"<<sizeof(float )<<endl;
    cout<<"sizeof(double)"<<sizeof(double )<<endl;
    cout<<"sizeof(char)"<<sizeof(char)<<endl;
//  sizeof不是函数是一个语句如果要计算的是类型需要有括号
//  如果计算的是某个具体的变量可以省略括号,但语法建议都加括号
    int i;cout<<"sizeof(int)"<<sizeof i<<endl;
    float f;cout<<"sizeof(float)"<<sizeof f<<endl;
    double d;cout<<"sizeof(double)"<<sizeof d<<endl;
    char c;cout<<"sizeof(char)"<<sizeof c<<endl;

    return 0;
}