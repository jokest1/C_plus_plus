//
// Created by 36302 on 2023/4/21.
//
/*
 * #define是在编译前进行处理和直接替换的如果报错只会报出经过替换后的数值错误不宜查找
 * #define常量无法创造出只属于某个部分的常量
 * 在编程种应该多用enum const inline去替换宏常量和宏展开
 * 使用inline修饰的函数会被近似于宏展开的形式内嵌到调用的位置,只适用于简单的逻辑代码
 * 在CPP编程中不要使用#define常量要用const enum inline 去替换用到宏的地方
 */
#include "test_base.h"
#define MAX(a,b)    ((a)>(b)?(a):(b))
const int NUM=1;//这是一个全局常量,在编译阶段才会被处理,报错会直接提示变量名字
const char* const STRING="123456";//常量字符串不仅要求指向他的指针是个常量还要求本身是个常量
const string STRING1("123456");//使用stl对字符数组的封装更加简洁高效的定义常量字符串
class TestConst{
public:
    const static int NOT_EXISTS=-1;
    enum{ Not_Exists=-1};
    inline int static Max(int i, int j){
        return i>j?i:j;
    }
};
int main(){
    cout<<"全局常量NUM="<<NUM<<endl;
    cout<<"类内专属常量="<<TestConst::NOT_EXISTS;
    {
        //这种类内常量可以强制转换为非常量然后改变内容
//        int *sum = (int *) &TestConst::NOT_EXISTS;
        //使用enmu去替换static const
        cout<<"类内局部常量="<<TestConst::Not_Exists<<endl;
//        &TestConst::Not_Exists;//enum不存在地址更加接近#define的语法;
    }
    {
        int i=10;
        int j=11;
        int sum=TestConst::Max(++i,j--);//更换掉宏展开为静态成员函数后会避免多次++和--
        cout<<"i="<<i<<" j="<<j<<endl;//对于i和j的值因为原样展开而会多次出现++和--而影响原值
        cout<<"i,j中最大的是:"<<sum<<endl;
    }
    return 0;
}