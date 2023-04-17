//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
/*
 * 在赋值时候如果对象类型不匹配则会寻找构造函数来进行隐式转换
 * 而通过加上explicit 来修饰构造函数则会禁止隐式调用
 */
using namespace std;
class mate{
    friend  ostream & operator<<(ostream& cout,const mate& m);
private:
    int i;
    double f;
public:
    mate(): i(0),f(0) {
        cout<<"调用了mate()"<<endl;
    }

    mate(int i) : i(i),f(0) {
        cout<<"调用了mate(int)"<<endl;
    }
    explicit mate(double f) : i(0),f(f) {
        cout<<"调用了mate(double)"<<endl;
    }
    mate(int i,float f):i(i),f(f){
        cout<<"调用了mate(int,float)"<<endl;
    }
};
ostream & operator<<(ostream& cout,const mate& m){
    cout<<m.i<<","<<m.f<<endl;
    return cout;
}

int main(){
    mate p;
    cout<<p<<endl;
    p=1;//将整数赋值给一个对象类型调用了隐式转换
    cout<<p<<endl;
    p=2.2;
    cout<<p<<endl;
    return 0;
}