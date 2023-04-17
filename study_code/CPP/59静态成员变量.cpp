//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
/*
 * 静态成员变量属于类内共有的,如果是public则在外部也可以放为不需要有类的对象就已经存在了
 * 静态成员函数可以被静态成员函数调用,但是非静态不能调用
 */
class teststic{
public:
    int i;
    static int j;
    static void print(){
        cout<<j<<endl;
    }
};
int teststic::j=11;
int main(){

    cout<<teststic::j<<endl;
    teststic::print();
    return 0;
}