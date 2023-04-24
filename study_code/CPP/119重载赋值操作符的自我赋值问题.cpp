//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 对于赋值=要考虑自我赋值的情况,尽量减少分支的选择和拷贝的调用
 * 在漏掉一些成员的初始化的情况下派生的调用也会漏掉这些的初始化这样的值是不确定的
 */
class baseTest{
private:
    int i;
    int j;
    int* ph= nullptr;
public:
    baseTest() {
        cout<<"调用了Base()"<<endl;
    }

    baseTest(int i) : i(i) {}

    //1.
//    baseTest& operator=(const baseTest& temp){
//        //通过暂存这个堆区地址
//        //然后重新构造后再删除源地址,即使自我拷贝也没有关系
//        auto t=temp.ph;
//        ph=new int(*(temp.ph));
//        delete ph;
//        return *this;
//    }
    //2.
//    baseTest& operator=(const baseTest& temp){
//        //创立两个分支如果地址相同就直接return
//        if(this==&temp)return *this;
//        delete ph;
//        ph=new int(*(temp.ph));
//
//        return *this;
//    }
    //3.
    baseTest& operator=(baseTest temp){
        //直接使用值拷贝然后交换内容
        swap(temp);
        return *this;
    }
    void swap(baseTest temp){
        baseTest t=temp;
        temp=*this;
        *this=t;
    }

    int getI() const {
        return i;
    }

    void setI(int i) {
        baseTest::i = i;
    }

    int getJ() const {
        return j;
    }

    void setJ(int j) {
        baseTest::j = j;
    }

    int *getPh() const {
        return ph;
    }

    void setPh(int *ph) {
        baseTest::ph = ph;
    }
};
class devirTest1:public baseTest{
private:
    int k;
public:
    devirTest1(int i, int k) : baseTest(i), k(k) {}

    devirTest1() {
        cout<<"调用了devirTest1()"<<endl;
    }
    void print(){
        cout<<"i:"<<getI()<<" j:"<<getJ()<<" k:"<<k<<endl;
    }
};
int main(){
    devirTest1 d1(10,11);
    d1.print();
    return 0;
}