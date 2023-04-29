//
// Created by 36302 on 2023/4/27.
//
#include "test_base.h"
/*
 * 为了防止是为了重写而因为书写错误而产生了重载而引入了override关键字
 * 通过引用修饰符来重载返回左值或者右值的成员函数,在()后边&表示返回的左值引用,&&表示返回右值引用的重载
 */
class test{
public:
    virtual void print()=0;
};
class test2:public test{
public:

//    void print(int i) override{}  因为override修饰符的修饰,书写错误变成重载无法通过编译
    void print() override{
        cout<<"重载了print"<<endl;
    }
};

class test3{
public:
    vector<int>vi;
    vector<int>& data()&{
        cout<<"左值引用"<<endl;
        return vi;
    }
    vector<int> data()&&{
        cout<<"右值引用"<<endl;
        return vi;
    }
};
int main(){
    test3 t3;
    auto av1=t3.data();
    auto av2=test3().data();//使用了临时变量但是仍旧是拷贝构造不如移动构造节约时间
    return 0;
}
