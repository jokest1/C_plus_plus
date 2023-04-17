//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
using namespace std;

int main(){
    int a=10;
    int b=20;
    long long c=30;
    cout<<"a+b+c:"<<a+b+c<<endl;//这里会自动提升到longlong

    float i=1.0f;
    double j=2.3;
    cout<<"i+j:"<<i+j<<endl;//这里会自动提升到double
    //在数值计算中会有隐形的类型转换自动转化为类型更大的数据类型

    unsigned int ui=(unsigned int )4294967295+1;//这里有数据截断告警使用强制类型转换,语法:(目标类型)数据.
    cout<<"ui:"<<ui<<endl;



}