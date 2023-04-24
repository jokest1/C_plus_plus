//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 虽然虚函数的调用是动态绑定但是默认的参数是静态绑定不运行修改
 * 这里好像是动态绑定?
 */
class base{
public:
    virtual void print(int no=10)=0;
};
class derive:public base{
public:
    void print(int no = 20) override{
        cout<<no<<endl;
    }
};
int main(){
    derive* spb=new derive();
    spb->print();
    delete spb;
    return 0;
}