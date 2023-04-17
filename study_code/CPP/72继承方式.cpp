//
// Created by 36302 on 2023/4/16.
//
#include <iostream>

using namespace std;
/*
 * 继承分为了三种方式继承:public 共有继承不能访问private 别的访问状态都保留
 *      protected 受保护继承 类外不能访问继承下来的public 和protected
 *      private 私有继承 继承下来的全为私有
 *  使用using可以修改访问树形语法: using 父类名::变量或者函数;
 */
class A{
private:
    int i;
protected:
    int j;
public:
    int k;
};
class B: protected A{
    void func(){
        cout<< this->j<<endl;
    }
};

int main(){
    B bb;
}