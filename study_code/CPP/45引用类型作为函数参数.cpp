//
// Created by 36302 on 2023/4/14.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * 传参分为了:传值,传地址,传引用
 * 引用类型的传参方式使得函数想要需改原数据内容得时候不必再传指针
 */
void fun1(int no,string name);
void fun2(int *no,string *name);
void fun3(int &no,string &name);
int main(){
    int no=1;
    string name="123";
    fun1(no,name);//传值后修改内容不影响原数据
    cout<<"no:"<<no<<" name:"<<name<<endl;
    fun2(&no,&name);//传地址后修改内容影响原数据
    cout<<"no:"<<no<<" name:"<<name<<endl;
    fun3(no,name);//传引用后修改内容影响原数据
    cout<<"no:"<<no<<" name:"<<name<<endl;
    return 0;
}
void fun1(int no,string name){
    no=8;
    name="789";
    cout<<"no:"<<no<<" name:"<<name<<endl;
}
void fun2(int *no,string *name){
    *no=8;
    *name="789";
    cout<<"no:"<<*no<<" name:"<<*name<<endl;
}
void fun3(int &no,string &name){
    no=8;
    name="789";
    cout<<"no:"<<no<<" name:"<<name<<endl;
}