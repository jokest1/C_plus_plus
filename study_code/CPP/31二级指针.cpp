//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;

void func(int** p);

int main(){
//    二级指针仍旧是一个指针,一个指向指针类型首地址的指针
//      通过二级指针可以修改他指向的指针地址的内容
//      如调用函数修改p在对内存放的数据p
    int *p=new int(20);
    cout<<*p<<endl;
    func(&p);
    cout<<*p<<endl;
    return 0;
}
void func(int** p){
    cout<<"**p:"<<**p<<endl;
    *p=new int(10);
}