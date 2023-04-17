//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>

using namespace std;
/*
 * 语法: 自定义类型& operator=(const 类型& 变量名);
 * 赋值运算符会由系统生成默认的但是却是浅拷贝,如果类内在堆区也有空间需要操作需要重写为深拷贝
 * 辅助语句和拷贝构造是不一样的,赋值语句是从对象到对象,而拷贝构造是从无到有
 */
class testEqual{
public:
    int age;
    int age1;
    int* p;
    testEqual(int age, int age1) : age(age), age1(age1),p(nullptr) {}

    testEqual(): testEqual(0,0) {}

    virtual ~testEqual() {
        if (p)
            delete p;
    }

    testEqual& operator=(const testEqual& t){
        if (&t== this)
            return *this;
        if (p!= nullptr){
            delete p;
        }
        p=new int(*t.p);
        age=t.age;
        age1=t.age1;
    }
};
int main(){
    testEqual t1(10,20);
    t1.p=new int(30);
    testEqual t2;
    cout<<t1.age<<","<<t1.age1<<","<<t1.p<<","<<*t1.p<<endl;
    cout<<t2.age<<","<<t2.age1<<","<<t2.p<<endl;
    t2=t1;
//  CPP提供了默认的赋值操作符重载,但是是浅拷贝如果在堆区存在数据则需要重写赋值操作符
    cout<<t2.age<<","<<t2.age1<<","<<t2.p<<","<<*t2.p<<endl;
    return 0;
}