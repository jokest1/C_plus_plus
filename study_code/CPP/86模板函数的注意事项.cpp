//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;
/*
 * 模板函数可以为类的成员函数创建模板,但是不能是虚函数和析构函数
 * 使用函数模板时候必须要明确类型
 */

class testTemp{
public:
    int m_i;
    int m_j;
    template<class T>
    void Swap(T& t1,T& t2){
        auto temp=t1;
        t1=t2;
        t2=temp;
    }
};


int main(){
    int i=10;
    int j=20;
    cout<<"i:"<<i<<" j:"<<j<<endl;
    testTemp tt;
    tt.Swap<int>(i,j);
    cout<<"i:"<<i<<" j:"<<j<<endl;
}