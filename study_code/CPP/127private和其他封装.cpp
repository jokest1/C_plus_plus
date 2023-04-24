//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 访问权限与代码的破坏量成为反比 private对代码的破坏量非常小
 * 而public改为private则将破坏所有代码
 */
class base1{
private:
    int i;
    int j;
    int k;
    int l;
};
//修改private为public 对派生类没有影响
//修改public为private 对派生类所有用到的地方报错
class drive1:public base1{
    int add(){
//        return k+l;
    }
};