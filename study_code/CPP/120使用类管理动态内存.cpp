//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 在函数内手动的new和delete管理动态内存如果delete之前发生了异常或者return内存就泄露了
 * 使用类去管理一片动态内存,将动态内存的地址放到管理类的成员变量中,将释放这片内存空间放入析构函数中
 * 这样在函数结束时候类销毁这片内存地址自动销毁
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
void func(){
    auto p=new baseTest();
    return;
    delete p;
}
void func1(){
    auto_ptr<baseTest> ap(new baseTest());
}
int main(){
    func1();
    return 0;
}