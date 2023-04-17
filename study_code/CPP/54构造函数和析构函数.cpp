//
// Created by 36302 on 2023/4/14.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * 构造函数和析构函数不需要返回值且由系统调用
 * 如果不写任何构造和析构函数会默认生成空的
 */
class test{
private:
    int m_no;
    string m_name;
public:
    test(){
        m_no=0;
        m_name= nullptr;
    }//构造函数可以重载的
    test(int no, const string &name) {
//        test()本意是调用无参构造先初始化一下然后再进行代参构造但是这里会生成一个匿名对象并不会进行无参构造
        m_no=no;
        m_name=name;
        cout<<"调用了test(int,string)构造函数"<<endl;
    }//对象在创建的时候一定会调用构造函数

    virtual ~test() {
        cout<<"调用了~test()析构函数"<<endl;
    }//对象在销毁时一定会调用析构函数
};

int main(){
//    test t2();//调用无参构造一定不要加括号会被解析为函数定义
    string temp("li");
    test t1(10,temp);
    return 0;
}