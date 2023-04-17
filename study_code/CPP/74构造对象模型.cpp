//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * 构造对象模型,派生类通过调用基类的构造函数来初始化基类的变量,派生类只负责初始化自己派生出来的变量
 * 基类可以引用或指向派生类的实例或地址,但是派生类不能指向基类,如重载的<<
 * 派生类也可以隐式转换为基类,在列表初始化中可以指定要调用的构造函数
 */
class people{
public:
    string name;
    int age;
    char sex;
    people(const string &name, int age, char sex) : name(name), age(age), sex(sex) {}
};
class man:public people{
public:
    man(const string &name, int age) : people(name, age, 'M') {}
};
class woman:public people{
public:
    woman(const string &name, int age) : people(name, age, 'W') {}
};
ostream &operator<<(ostream& cout,people p){
    cout<<"姓名:"<<p.name<<" 年龄:"<<p.age<<" 性别:"<<p.sex<<endl;
    return cout;
}

int main(){
    man l("张三",18);
    woman n("李四",20);
    cout<<l<<n<<endl;
    return 0;
}