//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 传递一个智能指针的时候如果在参数位置调用构造匿名函数的形式则因为执行顺序不固定而出现随机性内存泄漏
 * 将构造share_ptr指针封装为一个独立的语句或者在调用前用构造函数完成构造后传入,可以防止这种情况
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
int func(){

}
class baseTestHeap{
private:
    shared_ptr<baseTest*> spt;
public:
    baseTestHeap(const shared_ptr<baseTest *> &spt) : spt(spt) {}
};
shared_ptr<baseTest *> createHeap(baseTest* bt){
    return make_shared<baseTest*>(bt);
}
void testHeap(shared_ptr<baseTest *> hbt,int por){

}
int main(){
    auto wp=createHeap(new baseTest());
    auto wp2=make_shared<baseTest*>(new baseTest());
    testHeap(wp,func());
    testHeap(wp2,func());
    return 0;
}