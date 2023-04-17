//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * 1.分配出来的对空间没有变量名只有指向首地址的指针
 * 2.如果动态分配的内存不适用了一定要释放掉否则会耗尽内存
 * 3.用指针跟踪这片内存千万不要跟丢了
 */
int main(){
    int* p;                     //1.创建要动态分配的类型指针
    p=new int(10);              //2.用new在堆区分配一个int的内存空间初始化10;
    cout<<"*p= "<<*p<<endl;     //3.用解引用的方式来访问堆中的空间
    *p=20;                      //4.用解引用的方式修改空间中数据内容
    cout<<"*p= "<<*p<<endl;
    delete p;                   //5.不用之后使用delete来释放这片内存空间
    return 0;
}