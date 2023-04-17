//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;

void fun1(){
    cout<<"func1:"<<endl;
}
void fun2(){
    cout<<"func2:"<<endl;
}
void func1(void(*p)()){
    cout<<"11111\n";
    p();
    cout<<"11111\n";
}
/*
 * 通过函数指针可以使一个函数中运行大部分相同的代码,然后通过函数指针将不同的部分作为形参传递到函数中
 * 然后通过传入的函数指针来实现不同部分的实现
 */
int main(){

    func1(fun1);
    func1(fun2);

    return 0;
}