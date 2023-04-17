//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
/*
 * 形参设置了默认值不构成重载
 * 在含有隐式转换时候,有多个可匹配的隐式转换对应的重载函数则报错
 * 形参的默认值只能从右向左开始设置不能间隔
 */
void func1(int no,string name){
    cout<<"no:"<<no<<" string:"<<name<<endl;
}
void func2(int no,string name="li"){
    cout<<"no:"<<no<<" string:"<<name<<endl;
}
void func4(double no=8,string name="li"){
    cout<<"no:"<<no<<" string:"<<name<<endl;
}
void func4(long no=8,string name="li"){
    cout<<"no:"<<no<<" string:"<<name<<endl;
}
void func3(int no=8,string name="li"){
    cout<<"no:"<<no<<" string:"<<name<<endl;
}
int main(){
    func1(8,"wang");
    func2(9);
    func3();
//    func4(4);
    return 0;
}