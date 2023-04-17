//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
#include <string>

using namespace std;
/*
 * string是对C语言的字符数组进行了封装和改进
 */
int main(){
    string name="123";//string并不是内置类型而是C++标准库提供的类
    cin>>name;//读入一个string
    if(name=="12")//string可以进行比较
        cout<<"12";
    else
        cout<<name<<endl;
    string temp="12" "34" "56";//常量字符串不能使用+,可以直接连接
    cout<<temp;
    return 0;
}