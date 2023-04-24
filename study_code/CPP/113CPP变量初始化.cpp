//
// Created by 36302 on 2023/4/21.
//
#include "test_base.h"
/*
 * 变量的初始化会造成额外的成本就不在初始化,如:C语言的数组,在CPP中就不同于C语言vector容器就会初始化
 * 初始化的时候要分清楚初始化和赋值的行为,初始化后再赋值就会有额外成本
 * 内置类型要手动初始化,不初始化的内容会有不确定性
 * 对于跨单元的class 内 static 成员变量使用一个包装的getStaticXX函数进行定义后返回这个static变量
 * 因为static的唯一性如果内存中已经存在则不会再创建而直接返回这个static变量,解决了编译次序不定性著名的单例设计模式
 */
class Number{
public:
    Number(const string& m="",int mage=18,char ms='m')
    :name(m)    //写在构造函数后用:分割代表列表初始化通过传递的参数去调用对应的构造函数
    ,age(mage)  //还可以给默认参数来实现即使不传参数进行的默认构造
    ,sex(ms)    //列表初始化只有一次构造的调用没有额外的开销,列表初始化顺序应该与
                //成员变量定义的顺序一致,如果有基类则要先初始化基类
    {
        //写在{}内都是赋值,调用了default构造后又用=进行了覆盖
//        name="";
//        age=0;
//        sex='m';
    cout<<"Number的构造函数"<<endl;
    }
private:
    string name;
    int age;
    char sex;
};
class Numbers:public Number{
public:
    Numbers(const string& m="",int mage=18,char ms='m',const string &address="")
    : Number(m,mage,ms)
    ,address(address)
    {
        cout<<"Numbers的构造函数"<<endl;
    }
    const int& getINDEX(){
        //将类内静态变量放入成员函数创建
        // 这样避免了初始化顺序的问题同时也可以只在调用后创建
        static int NOT_INDEX=-1;
        return NOT_INDEX;
    }
private:
    string address;
};
int main(){
    Numbers ns("12",10,'n',"baoding");
    return 0;
}