//
// Created by 36302 on 2023/4/23.
//
#include "test_base.h"
/*
 * 在cpp中转型动作是非常浪费效率的即使认为只是不同的内存读取认知,但是int和double处理的部件和存储方式都不同
 * 所以转换的时候一定有动作出现的
 * 而派生类转基类且时候实际上会产生一个临时的基类保存数据,验证一下是否存在这个基类
 * 这个编译中这种行为直接报错
 */
class base{
public:
    int i;
    int j;
    base(int i, int j) : i(i), j(j) {}
    virtual void print(){
        cout<<"i: "<<i<<"j:"<<j;
    }
};
class dd:public base{

public:
    int k;
    dd(int i, int j, int k) : base(i, j), k(k) {}

    void print() override {
        base::print();
        cout<<"k:"<<k;
    }
};
int main(){
    dd d1(10,11,12);
//    dynamic_cast<base>(d1).i=20;
//    dynamic_cast<base>(d1).j=30;
    return 0;
}