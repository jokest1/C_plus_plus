//
// Created by 36302 on 2023/4/17.
//
#include <iostream>
/*
 * 只适用于包含虚函数的类
 * 可以用于引用，但是，没有与空指针对应的引用值
 */
using namespace std;
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
    void print(){
        cout<<"nan"<<endl;
    }
};
class woman:public people{
public:
    woman(const string &name, int age) : people(name, age) {}

    void show() override {
        cout<<"女:"<< this->name<<","<< this->age<<endl;
    }
    void printf(){
        cout<<"nv"<<endl;
    }
};
int main(){
    people* p= nullptr;
    p=new man("zh",18);
//    想要使用派生类独有的print函数但是基类中没有这个的虚函数需要进行类型转换
    man* mp=dynamic_cast<man*>(p);
    //dynamic_cast<类型指针>(指针变量)用于判断是否可以安全转换过去,不可以返回nullptr
    if(mp){
        mp->print();
    }
    delete p;
    p=new woman("en",17);
    woman* wp=dynamic_cast<woman*>(p);
    if(wp){
        wp->printf();
    }
    return 0;
}