//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 异常安全性修改动态资源数据:1.保证内存不会泄露2.保证操作失败后不会修改数据和结构
 */
class test{
    //一个类有一片堆存放数据,并且记录修改的次数
public:
    test(int n) : arr(make_shared<int*>(new int(n))),count(0) {}
//    void setData1(int n){
//        //这个修改方法异常安全性极低,内存泄露+数据破坏
//        int* temp=new int(n);//开辟一片内存并放入修改后数据
//        ++count;            //修改次数加1
//        delete arr;         //删除原有内存
//        arr=temp;           //移交地址
//    };
    void setData2(int n){
        //改进上述的修改方法,将指针改为智能指针
        //内存管理改进为资源类管理,在没有抛出异常的可能后再修改数据内容
        shared_ptr<int*> temp= make_shared<int*>(new int(n));
        arr.reset(temp.get());
        ++count;
    }
private:
    shared_ptr<int*>  arr;
    int count;
};