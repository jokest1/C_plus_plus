//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>

using namespace std;
/*
 * 基类的引用或指针可以指向派生类
 * 所以在继承的方法中可以在形参写基类型在实现中再判断具体的派生类型
 * 基类指针或引用只能调用基类的方法和变量
 */
class animal{
public:
    string name;
    string speck;

    animal(const string &name, const string &speck) : name(name), speck(speck) {}
};
class cat:public animal{
public:
    int age;

    cat(const string &name, const string &speck, int age) : animal(name, speck), age(age) {}
};
class dog:public animal{
public:
    int length;

    dog(const string &name, const string &speck, int length) : animal(name, speck), length(length) {}
};

ostream & operator<<(ostream& cout,animal& a){
    cout<<a.name<<":"<<a.speck<<"!"<<endl;
    return cout;
}
int main(){
    cat c("mimi","miao~",10);
    dog d("gougou","wang!",20);
    cout<<c<<d<<endl;
    return 0;

}