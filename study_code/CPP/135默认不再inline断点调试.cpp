//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 写在类内的函数实现会默认inline,类内所有方法实现还是在类外实现较好,通过关键字决定inline
 */
class test1{
public:
    test1(int i=0) : i(i) {}

    void print(){
        int j=10;
        cout<<j<<endl;
        j=11;
        cout<<j<<endl;

        cout<<"i:"<<i<<endl;
    }
private:
    int i;
};
class test2{
public:
    test2(int i=0) : i(i) {}

    void print();
private:
    int i;
};
void test2::print() {
    int j=10;
    cout<<j<<endl;
    j=11;
    cout<<j<<endl;

    cout<<"i:"<<i<<endl;
}
int main(){
    test1 t1;
    test2 t2;

    t1.print();
    t2.print();
    return 0;
}