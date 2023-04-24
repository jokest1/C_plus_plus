//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 对于资源的管理类因该提供返回底层资源的函数,因为API是不会使用自定义管理为参数的
 * 需要从资源管理类中取出底层的资源才能参与apt的调用
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
    baseTest* getHeap(){
        return reinterpret_cast<baseTest *>(btp.get());
    }
};