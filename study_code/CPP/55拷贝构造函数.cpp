//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
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
    //还有以一种特别的构造方法就是拷贝构造,用同一个类的变量进行构造,形参一定是const的类名引用
    test(const test& t){
        m_no=t.m_no;
        m_name=t.m_name;
    }
    virtual ~test() {
        cout<<"调用了~test()析构函数"<<endl;
    }//对象在销毁时一定会调用析构函数
};
int main(){

    test t1;
    test t2(t1);//调用拷贝构造
    test t3=t1;//调用拷贝构造
    test t4;//t4的创建和t3的创建是不一样的东西t4使用了无参构造+赋值运算
    t4=t1;
    return 0;
}