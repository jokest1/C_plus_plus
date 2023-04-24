//
// Created by 36302 on 2023/4/19.
//
#include "test_base.h"
namespace testName{
    /*函数的重载
     * 相同的函数名通过不同的形参类型,在调用时候通过传递的参数类型来决定具体的调用
     */
    void heavy(int i);
    void heavy(int i,float f);
    void heavy(int i,float f,double d);
    void heavy(int i,float f,double d,char c);

    /*
     * 函数的默认值
     *      必须从右向左进行设置,在重载时候使用默认值会造成重载时候的二义性调用
     */
    void defaultSum(int i,int j=10);
}
namespace structToClass{
    /*
     * 结构体通过将各种数据类型打包起来用作个人定制的类型
     */
    struct data{
        int i;
        int j;
    };
    /*
     * 类通过将各种数据和对这些数据的操作打包起来用作个人定制的一种对象
     * 类内通过修饰符来控制变量和方法的调用有三种:private,protected,public
     */
    class cla{
    public:
        int i;
        int j;
        static int  si;
        /*
         * 基本数据类型需要初始化,而类的初始化成为构造,构造一个类需要在类内有对应的构造函数
         * 构造函数可以重载,根据传递的参数类型来决定调用的构造函数
         * 析构函数是在类消失的时候调用的遗言,一般在类内使用了动态内存管理的时候才会写析构函数
         * 析构函数无法重载是唯一的函数以~开头
         */
        cla(int i=0, int j=0) : i(i), j(j) {}
//拷贝构造函数用一个类来初始化一个类,这里必须要引用,如果不是引用则传参时候需要调用拷贝构造,进入创建和使用的死循环
        cla(const cla& cl){}
//  初始化列表:构造函数分为初始化阶段和运行阶段,const修饰的成员变量需要使用列表进行初始化
//        语法 构造函数():初始化列表{运行赋值语句}

//    使用const修饰来保证函数体内对类无任何修改
        int getI()const{
            return i;
        }

//    this指针是默认传递的在成员函数()后传递this,而const修饰的就是隐式传递的this
        int getJ()const{
            return this->j;
        }
    };
    //类内静态成员变量因为即使不创建类也会在静态区保存这个变量所以需要类外初始化
    int cla::si=10;
    /*
     * 在C语言中函数和变量并没有什么练习
     * 但在C++中通过类来表述抽象数据类型,并且通过指针将类成员函数和成员变量联系起来
     */
}
namespace testFriend{
    /*
     * 在类内成员被private修饰是无法在类外访问的但是如果将某个全局函数通过friend修饰就可范围类内变量
     */
    class GG{
        //声明了友元可以访问类内变量
        friend void print(const GG& gg);
    private:
        int no;
        string name;
    public:
        GG(int no=0, const string &name="123") : no(no), name(name) {}
    };
    void print(const GG& gg){
        cout<<"GG::no"<<gg.no<<"  GG::name"<<gg.name;
    }
}
int main(){
    testFriend::GG g(10,"wang");
    testFriend::print(g);
    return 0;
}