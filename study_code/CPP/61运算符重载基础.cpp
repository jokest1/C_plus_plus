//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>
using namespace std;

/*
    1.在C++中定义了特殊的重载函数将函数名为operate<重载的符号>函数,可以使用特殊的方式调用函数
    2.形参的顺序影响符号两侧的数据类型,重载操作符号分为了成员函数重载和友元重载二者取其一
    3.使用成员函数重载时候使用this指针传递类类型,重载函数必须有一个是自定义成员不运行重载基本类型运算符
    4.重载的操作符含义语法要符合操作符本身语义
 */
class student{
//    将加分函数声明为友元
//    friend void operator+(student& st,int sum);
private:
    string name;
    int scout;
public:
    student(const string &name, int scout) : name(name), scout(scout) {}

    void show(){//打印类函数
        cout<<"学生:"<<name<<" 成绩:"<<scout<<endl;
    }
    student& operator+(int sum){
        scout+=sum;
        return *this;
    }
};

//void addScout(student& st,int sum){
//    st.scout+=sum;
//}
//void operator+(student& st,int sum){
//    st.scout+=sum;
//}
int main(){
    student st("zhang",80);
    st.show();
//    给成绩加20分使用C语言方式
//    addScout(st,20);
//    st.show();
    st+20+10+5;
    st.show();
return 0;
}