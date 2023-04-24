//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 对于资源管理类的copy设计有四种方式:1.禁止copy 2.浅拷贝 3.深拷贝 4.移动
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
class baseTestHeap{
private:
    shared_ptr<baseTest*> btp;
//    baseTestHeap(const baseTestHeap&)=delete;           //处理方式1直接禁止copy
//    baseTestHeap& operator=(const baseTestHeap&)=delete;//处理方式1直接禁止copy
public:
    baseTestHeap(baseTest *btp) : btp(make_shared<baseTest*>(btp)) {}//通过count_ptr浅拷贝

};