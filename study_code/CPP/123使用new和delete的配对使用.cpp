//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 在使用new[] 创建了五个类发生了五次构造函数调用,而delete后发生了一次的析构产生了内存泄漏
 * 而使用delete[]后调用与构造相同个数的析构函数
 */
class baseTest{
private:
    int i;
    int j;
public:
    baseTest() {cout<<"调用了Base()"<<endl;}
    ~baseTest(){
        cout<<"调用了~Base()"<<endl;
    }
};
int main(){
    baseTest *vb=new baseTest[5]{ baseTest(),baseTest(),baseTest(),baseTest()};
    delete[] vb;
    return 0;
}