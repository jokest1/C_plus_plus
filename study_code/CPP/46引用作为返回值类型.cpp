//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
//返回一个临时变量的引用报错
int& fun1(int& a){
    ++a;
    return a;
}

const int& fun2(const int& a){
//    ++a;//通过const关键字限制函数体内对数据的修改
    return a;
}
int main(){
    int i=10;
    int& ii=fun1(i);
    fun1(i)=100;//通过引用修改了i的内容
//    fun2(i)=1000;通过增加了const关键字限制行为
    cout<<i<<endl;
    cout<<ii<<endl;
    return 0;
}