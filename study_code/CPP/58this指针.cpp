//
// Created by 36302 on 2023/4/14.
//
#include <iostream>
#include <string>
using namespace std;

class testThis{
private:
    string name;
    int no;
public:
    testThis(const string &name, int no) : name(name), no(no) {}
    const testThis& cmp(const testThis& temp)const{
        if (temp.no<no)
            return temp;
        return *this;
    }
        void print(){
        cout<<"no:"<<no<<" name"<<name<<endl;
    }
};

int main(){
    //创建对象的时候内存中只是存放了变量,方法都是唯一的放在了代码段
    //通过隐式传递一个this 指向调用函数对象的指针去判断是谁调用了方法
    testThis one("张三",3);
    testThis two("李四",5);
    testThis temp = one.cmp(two);
    temp.print();
    return 0;
}