//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 在基类和派生类之间相同的函数可能要作不同的工作
 * 这个时候将这个函数声明会virtual就可以用基类指针根据不同派生类产生不同的实现方法
 * 声明函数为virtual会长生vptr指向一个函数调用的数组,验证占据内存空间
 * 两个int占8字节出现virtual后增加为16字节,多了一个指针大小
 */
class baseTest{
private:
    int i;
    int j;
public:
    baseTest() {cout<<"调用了Base()"<<endl;}
    virtual void testV(){

    }
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
    cout<<"现在没有virtual.基类的内存大小:"<< sizeof(baseTest)<<endl;//8B
    cout<<"现在有virtual.基类的内存大小:"<< sizeof(baseTest)<<endl;   //16B
    return 0;
}