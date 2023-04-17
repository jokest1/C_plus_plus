//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
#include <string>
/*
 * 传递数据的内存地址对于较大的空间类型来说,直传8个自己的地址更加快不用复制整片空间
 */
using namespace std;
void print(int no,string name);
void print(int no,string* name);
int main(){
    int no=5;
    string name="123456789";
    print(no,name);
    print(no,&name);
}
//通过指针传参降低了拷贝数据的空间,提高了拷贝效率
void print(int no,string name){
    cout<<"sizeof(no)"<< sizeof(no)<< "sizeof(name)"<<sizeof(name)<<endl;//传递了4+32字节
    cout<<"no:"<<no<<"name:"<<name<<endl;
}
void print(int no,string* name){
    cout<<"sizeof(no)"<< sizeof(no)<< "sizeof(name)"<<sizeof(name)<<endl;//传递了4+8字节
    cout<<"no:"<<no<<"name:"<<*name<<endl;
}