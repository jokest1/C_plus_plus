//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 编译默认提供的函数对于设计的类不应该使用的时候要显示的声明这些函数不该使用
 * 方法有两种:把这些函数声明为private或者使用delete删除掉
 */
class Test1{
private:
    Test1();
    Test1& operator=(Test1&);
public:
};
class Test2{
private:
    Test2()=delete;
    Test2& operator=(Test1&)=delete;
public:
};