//
// Created by 36302 on 2023/4/23.
//
#include "test_base.h"
/*
 * 如果某个类的构造函数只有一个参数会有隐式转换存在的,而this是禁止被隐式转换的
 * 现在有一个分数类,由于分数允许和整数相乘同时要满足交换律
 * 因为this是不允许进行隐式转换的,这个时候需要去重写全局的*允许前一个参数为int后一个为rational类
 */
class rational{
public:
//    这个构造函数可以在提供一个int的时候产生隐式转换
    rational(int numerator, int denominator=1)
    : numerator(numerator), denominator(denominator)
    {}
    const rational operator*(const rational& r){
        return rational(numerator*r.numerator,denominator*r.denominator);
    }
    void print()const{
        cout<<"分子是:"<<numerator<<" 分母是:"<<denominator<<endl;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};
const rational operator*(const rational& l,const rational& r){
    return rational(l.getNumerator()*r.getNumerator(),l.getDenominator()*r.getDenominator());
}
int main(){
    rational r1(1,2);
    rational r2(1,2);
    (r1*r2).print();
    (r1*3).print();//int可以通过隐式转换为有理数类但是顺序不能颠倒
    (4*r1).print();//因为非成员函数重写了*可以对前一个进行了隐式转换
    return 0;
}