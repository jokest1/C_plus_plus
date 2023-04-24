//
// Created by 36302 on 2023/4/23.
//
#include "test_base.h"
/*
 * 在循环中存在两种变量的使用方式:1次构造n次赋值1次析构,n次构造n次析构
 * 根据不同的类的大小在这两种方式中选择较为高效的一种
 */
class testCopy{
public:
    testCopy(int i, int j) : i(i), j(j) {}
    int i;
    int j;
};
class testTime{
public:
    void func1(){
        testCopy tc(1,1);
        for (int i = 0; i < 10000; ++i) {
            tc.i=i;
            tc.j=i;
        }
    }
    void func2(){
        for (int i = 0; i < 10000; ++i) {
            testCopy(i,i);
        }
    }
};
template<typename T>
void Timer(std::string name,T* obp, void(T::*fp)(void)){
    auto start=std::chrono::steady_clock::now();
    (obp->*fp)();
    auto df=std::chrono::steady_clock::now()-start;
    std::cout<<name<<"运行时间: "<<df.count()<<"ns"<<std::endl;
}
int main(){
    testTime tt;
    Timer("一次构造",&tt,&testTime::func1);
    Timer("多次构造",&tt,&testTime::func2);
    return 0;
}