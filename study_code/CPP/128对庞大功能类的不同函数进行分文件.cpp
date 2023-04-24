//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 对于一个庞大功能的类可以按照类内功能分为不同的头文件将主要部分放在基类头文件和相同的namespace中
 * 之后根据功能细分头文件包含基类文件然后用非成员函数去组合类内功能实现组合功能
 * 只要不被调用声明没有定义也没有关系
 */
namespace n1{
    class test{
    public:
        void a1(){cout<<"a1"<<endl;}
        void a2(){cout<<"a2"<<endl;}
        void a3(){cout<<"a3"<<endl;}
        void a4(){cout<<"a4"<<endl;}
        void a5(){cout<<"a5"<<endl;}
        void a6();
    };
    void print(test& t1){
        t1.a1();
        t1.a2();
        t1.a3();
        t1.a4();
        t1.a5();
    }
}
namespace n1{
    void b1(){cout<<"b1"<<endl;}
    void b2(){cout<<"b2"<<endl;}
    void b3(){cout<<"b3"<<endl;}
    void b4(){cout<<"b4"<<endl;}
    void b5(){cout<<"b5"<<endl;}
}
namespace n1{

    void c1(){cout<<"c1"<<endl;}
    void c2(){cout<<"c2"<<endl;}

}
namespace n1{
    void d1(){cout<<"d1"<<endl;}
    void d2(){cout<<"d2"<<endl;}
}
int main(){
    n1::test t2;
    n1::print(t2);
    return 0;
}