//
// Created by 36302 on 2023/4/27.
//
#include "test_base.h"
/*
 * C++有多种初始化的方式而在C++11中又增加了{}初始化
 * 动态数组初始化用来可以避免使用无参构造时候的解析语法为定义
 * {}禁止进行隐式转换,虽然{}和()可以替换使用但是使用{}时候动态数组初始化的优先级最高
 * 对于空{}做了特殊处理将其视为无参数类型
 */
class test{
public:
    test() {
        cout<<"无参构造"<<endl;
    }
    test(int i,bool b):i(i),b(b) {
        cout<<"带参构造"<<endl;
    }
    test(initializer_list<int> ib) {
        cout<<"列表构造"<<endl;
    }
    int i;
    bool b;
};

int main(){
    test t1{};
    test t2{1,1};
    return 0;
}