//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 可以通过基类指针指向派生类,设计一个函数可以根据需要创建不同的派生类
 */
class baseTest{
private:
    int i;
    int j;
public:
    baseTest() {cout<<"调用了Base()"<<endl;}
};
class devirTest1:public baseTest{
public:
    devirTest1() {cout<<"调用了devirTest1()"<<endl;}
};
class devirTest2:public baseTest{
public:
    devirTest2() {cout<<"调用了devirTest2()"<<endl;}
};
class devirTest3:public baseTest{
public:
    devirTest3() {cout<<"调用了devirTest3()"<<endl;}
};

baseTest* createClass(int i){
    if (i=1){return new devirTest1();
    }else if(i=2){return new devirTest2();
    }else{return new devirTest3();}
}

int main(){
    delete createClass(1);
    delete createClass(2);
    delete createClass(3);
    return 0;
}