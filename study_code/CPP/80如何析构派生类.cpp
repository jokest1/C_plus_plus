//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;
/*
 * 虚函数要求基类和派生类一致但是对析构函数做了特殊处理
 * 虽然多态在构建派生类的时候会层层构造
 * 但是析构的时候如果没有将析构函数声明为虚函数,析构时只会析构基类
 * 赋值运算符函数不能继承
 */
class AA{
public:
    AA() {
        cout<<"调用了AA()的构造函数"<<endl;
    }

    virtual ~AA() {
        cout<<"调用了~AA()的析构函数"<<endl;
    }
};
class BB:public AA{
public:
    BB() {
        cout<<"调用了BB()的构造函数"<<endl;

    }
    virtual ~BB() {
        cout<<"调用了~BB()的析构函数"<<endl;
    }
};
int main(){
    //通过AA的指针指向了派生类但是析构的时候没有调用BB的析构函数
//    因为析构函数没有发生多态,无法在运行时确定析构类型,将基类函数析构声明为析构函数
    AA * pa=new BB();
    delete pa;
    cout<<"--------声明后--------"<<endl;
    AA *af=new BB();
    delete af;
    return 0;
}