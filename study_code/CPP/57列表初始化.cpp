//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;

class TestList{
private:
    int i;
    int& j;
public:
    TestList(int i, int &j) : i(i), j(j) {}//构造函数分为了计算阶段和运行阶段
    //在构造函数的形参列表后边用冒号开头变量(初始化内容),进行列表初始化可以初始化const修饰的变量和引用
}

int main(){

    return 0;
}