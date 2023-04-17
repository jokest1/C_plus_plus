//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * cpp允许重载类型转换函数语法operator 类型名称() 不允许有含返回值和形参
 * 通过自定义类型转换的过程来实现想要的转换过程
 * explicit可以修饰类型转换符
 */
class people {
private:
    string name;
    int age;
public:
    people(const string &name, int age) : name(name), age(age) {}

    operator string() {
        string temp;
        string a(""+age);
        temp = temp + name+a;
        return temp;
    }
};
int  main(){
    people p("张",10);
    cout<<(string)p<<endl;
    return 0;
}