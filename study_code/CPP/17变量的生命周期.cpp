//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;

void func1();
void func2();
void func3();
void func4();
void func5();
int a=10;
/*
 *全局变量定义在全局区定义后,后边的所有函数都可以使用在程序结束的时候释放
 * 局部变量只能在定义后到语句块范围内使用执行出语句块系统释放
 * static静态变量只会初始化一次且只能在定义范围内使用但是具有全局的生命周期
 *想要在函数内优先使用全局变量加::修饰就可以
 */
int main(){
    func1();
    func2();
    cout<<"main "<<a<<endl;

    func3();
    func3();
    func3();
    func3();
    return 0;
}
void func1(){
    cout<<"func1 "<<a++<<endl;
}
void func2(){
    cout<<"func2 "<<a++<<endl;
}
void func3(){
    int i=10;
    int j=10;
    static int k=10;
    cout<<"func3 i:"<<i++<<endl;
    cout<<"func3 j:"<<j++<<endl;
    cout<<"func3 k:"<<k++<<endl;
}
void func4(){
    cout<<"func4"<<a++<<endl;
}
void func5(){
    cout<<"func5"<<a++<<endl;
}