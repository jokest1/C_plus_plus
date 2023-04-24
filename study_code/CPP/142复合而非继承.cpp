//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
/*
 * 使用复合的方式在一个类内包含某个类然后对类的操作进行封装实现功能
 */
class stack{
public:
    void push(int n){
        vt.push_back(n);
    }
    int pop(){
        int old=vt.back();
        vt.pop_back();
        return old;
    }
private:
    vector<int> vt;
};