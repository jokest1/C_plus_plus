//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;
/*
 * 当基类方法没有具体实现需要根据派生类产生具体的实现
 * 可以将函数声明为纯虚函数,语法: vietual 返回值 函数名()=0;
 * 还有纯虚函数的类成为抽象类不允许实例化,只有在实现了虚函数后才可以实例化
 */
class people{
protected:
    string name;
    int age;
public:
    people(const string &name, int age) : name(name), age(age) {}

    virtual void show()=0;
};
class man:public people{
public:
    man(const string &name, int age) : people(name, age) {}

    void show() override {
        cout<<"男:"<< this->name<<","<< this->age<<endl;
    }
};
class woman:public people{
public:
    woman(const string &name, int age) : people(name, age) {}

    void show() override {
        cout<<"女:"<< this->name<<","<< this->age<<endl;
    }
};
int main(){
    man m("zh",18);
    woman w("en",17);
    m.show();
    w.show();
    return 0;
}