//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * 通过重载()运算符使得对象名()就可以调用函数,可以创造仿函数
 * 如果与全局函数同名则按照查找规则调用
 * 本质仍旧是个类可以存放更对的数据内容
 */
void show(string temp){
    cout<<"调用全局函数:"<<temp<<endl;
}
class testShow{
public:
    void operator()(string temp){
        cout<<"调用局部函数:"<<temp<<endl;
    }
};
int main(){
    show("寄了");
    testShow show;
    show("寄吧");
    return 0;
}