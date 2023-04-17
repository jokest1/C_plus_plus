//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
#include <string>

//1.void v;void不能定义变量
//2.其他类型指针转为void指针不需要强制类型转换
//3.void*转其他类型需要强制类型转换
//void可以占位无参或者无返回值
using namespace std;
void func1(string name,void* pVoid);
void func2(string name,int * pVoid);

int main(){
    string name="a ";

    int i=10;
    char c='1';
    void* tv= nullptr;
    func1(name,&i);
    func1(name,&c);
    func2(name,(int*)tv);
    return 0;
}
void func1(string name,void* pVoid){

    cout<<name<<pVoid<<endl;
}
void func2(string name,int * pVoid){
    //
    cout<<name<<pVoid<<endl;
}