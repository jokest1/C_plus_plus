//
// Created by 36302 on 2023/4/19.
//
#include "test_base.h"
void test1(){
//    C++的数据类型:整型/浮点型/字符串
//    数据类型是语法上的的解释,在内存中只是代表了不同大小的连续内存空间
    int i=10;
    cout<<"int类型占"<< sizeof(int)<<"B"<<",i="<<i<<endl;
    double d=10.0;
    cout<<"double类型占"<< sizeof(double )<<"B"<<",d="<<d<<endl;
    string str="字符串字符串字符串";
    //string固定为了24字节是因为他不是基本数据类型,通过三个指针在堆区动态管理的数据
    cout<<"string类型占"<< sizeof(string)<<"B"<<",str="<<str<<endl;

//    C++输出数据
//    cout是iostream库中的变量名,代表了控制台通过<<左移运算符将右侧的数据输出到控制台
    cout<<"hello word!"<<endl;

    //单行注释,以双/代表注释一行
    /* (以/和*开始)(以*和/结束) 注释两个之间的所有内容
     * 多
     * 行
     * 注
     * 释
     */
}
void test2(){
//    变量是内存变量的简称,用于存放数据
//    语法: 变量类型 变量名 [初始化]   //[]代表可选内容
//    常用的数据类型有: int整型   float单精度    double双精度   char字符型     bool布尔值
//                  string 字符串类型[这个不是基本数据类型而是CPP的STL提供的封装字符串]
    int i=10;
    int j;
    j=10;//定义i初始化为10,和定义j后赋值为10是两种不同的操作
    float f;
    double d;
    char c;
    bool b;
    string s;
    i=20;
    //没有初始化过的变量是垃圾值,不建议定义时不初始化变量
    cout<<"i="<<i<<"f="<<f<<"d="<<d<<endl;

    //    常量代表不可改变的内容有:define定义的宏常量,const修饰的语法上的常量
    //      常量必须要初始化
//#define I 10;
    const int ci=10;
}
void test3(){
    /*
     * cin是iostream库提供的变量名用途是从控制带读取数据
     * 读取的数据会放在输入缓冲区,如果是输入bool:0代表false,!0代表true
     */
    int i=0;
    int j=0;
    cin>>i>>j;
    cout<<"i="<<i<<",j="<<j<<",i+j="<<i+j<<endl;
}
void test4(){
    /*
     * CPP的运算符代表了某种特定的运算,运算符规定了使用的数据类型运算的结果,不同语境下运算符含义不同
     */
//    算数运算符:数学上的加减乘除和求余数
    int i=10;
    int j=20;
    int sum=0;
    cout<<"i+j="<<i+j<<endl;
    cout<<"i-j="<<i-j<<endl;
    cout<<"i*j="<<i*j<<endl;
    cout<<"i/j="<<i/j<<endl;//如果没有浮点型参与运算则舍弃小数部分,去尾法
    cout<<"i%j="<<i%j<<endl;
    cout<<"float/0.0="<<1.0/0.0<<endl;//浮点型除0出现,inf代表无穷大,整型则直接报错

//    自增自减运算符:对自己进行增加1或者减少1的操作
    int i1=10;
    cout<<"++i"<<++i<<endl;
    cout<<"i++"<<i++<<endl;
    cout<<"--i"<<--i<<endl;
    cout<<"i--"<<i--<<endl;
    cout<<"i"<<i<<endl;

//    逻辑运算符
//    有:与&&   或||     非!
//    真&&真->真   假||真->真     !真->假
}
void test5(){
    /*
     * C++11提供了一种区别于定义时用=初始化的方式使初始化语义更加明显,在定义变量的时候在变量后使用(初始值)的方式
     */
    int i(10);
    cout<<i<<endl;
//    int j();如果不初始化或者使用默认初始化不要加这个()会被解析为函数定义

}
void test6(){
    /*
     * if(条件表达式){语句}
     */
    if(true){
        cout<<"条件报答是为真"<<endl;
    }
//    if后边可以跟一个配对的else 表达为如果表达式不成立则执行
    if (false){cout<<"条件报答是为真"<<endl;}
    else{cout<<"条件报答是为假的"<<endl;}
//    if和else只有一个意外还有增加分支的手段在两个之间使用else if(表达式),上方的分支优先级高于下方
    if(true)
        cout<<"条件报答是为真"<<endl;
    else if(true)
        cout<<"条件报答是为真"<<endl;
    else
        cout<<"条件报答是为真"<<endl;
    /*
     * 循环语句while(表达式)不定循环 for(;;)定量循环
     */
    char c=0;
    while ((cin>>c)&&c!='q'){//只有表达式不成立才会结束循环
        cout<<"c!=q"<<endl;
    }
    for (int i = 0; i < 5; ++i) {//定量循环
        cout<<"这是第"<<i<<"次循环"<<endl;
    }
}
/*
 * 函数的定义语法: 返回值类型 函数名(形参列表) {函数体}
 *      C11增加:auto 函数名(形参列表)->返回值类型 {函数体}
 * 定义可以多次定义,但是只有一次实现
 * return可以有多个,return的类型要与返回值类型一致,传参会有隐式转换没有返回值可以void占位
 */
int max(int a,int b);
auto max(int a,int b)->int;

void test7(){
    /*
     * 变量的作用域和生命周期
     * 变量分为:全局变量    局部变量    静态变量
     * 定义在全局区域是全局变量     在函数内定义或者函数的形参是局部变量      static修饰的是静态变量
     */
}
void test8(){
    /*
     * 原始字面量（值）可以直接表示字符串的实际含义，不需要转义和连接
     * 语法: R"[标签]()[]"
     */
    cout<<R"abc(/n/n//n/n//n/n/n/n/n/n/n/n/n/n/n/n//n/n)abc"<<endl;
}
int main(){
//    数据类型和输出
//    test1();

//    使用变量和常量
//    test2();

//    数据的输入
//    test3();

//    CPP的运算符
//    test4();

//    C++11的初始化操作
//    test5();

//    CPP的三种运行结构:顺序结构,选择结构,循环结构
//    test6();

//    函数的定义和声明
//    函数名()实际传入的参数进行调用
//    cout<<max(10,20)<< endl;

//    原始字面量
    test8();
    return 0;
}

int max(int a,int b){
    return a>b?a:b;
}