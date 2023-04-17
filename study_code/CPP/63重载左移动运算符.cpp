//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>
/*
 * 左移运算的重载只能写非成员函数的版本因为成员函数版本的第一个形参固定为this指针了
 * 而形参的顺序决定了运算符号两边的数据类型所以 类型<<cout并不符合运算符的语义
 */
using namespace std;
//自动类people包含姓名和年龄
class people{
    friend ostream & operator<<(ostream& cout,const people & p);
private:
    string name;
    int age;
public:
    people(const string &name, int age) : name(name), age(age) {}
    void show(){
        cout<<"姓名:"<<name<<" 年龄:"<<age<<endl;
    }
};
ostream & operator<<(ostream& cout,const people & p){
    cout<<"姓名:"<<p.name<<" 年龄:"<<p.age<<endl;
    return cout;
}
int main(){
    people one("张三",18);
    one.show();//实现了toString的功能但是不符合特性
    cout<<one<<endl;//符号打印的写法但需要重载<<,调用了非成员的版本

    return 0;
}