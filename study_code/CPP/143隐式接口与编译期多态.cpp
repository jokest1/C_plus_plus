//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 模板类的运行过程中调用的所有的方法都是对类的隐形接口
 * 如果类没有实现这些隐形接口则无法调用这个函数模板
 * 编译的时候就会确定调用的是那个类的成员函数
 */
template<class T>
void test(const T &temp) {
    if (temp.size() > 0) {      //T类型要有size()函数
        temp.print();           //T类型要有print()函数
    }
}


class cl1{
public:
    int size()const{
        cout << "调用了size()" << endl;
        return 1;
    }
    void print()const{
        cout<<"调用了print()"<<endl;
    }
};

int main() {
    cl1 t1;
    test(t1);   //编译的时候就确定了运行哪个类的函数
    return 0;
}