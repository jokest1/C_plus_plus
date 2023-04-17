//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
#include <string>
using namespace std;
/*
 * 变量就是申请一片连续的内存空间,数据类型决定了这点连续的空间的多少,变量名代表了这片连续空间的地址
 * 这片连续空间的数据可以任意修改数据内容
 */
int main(){
    string name;
    int age;
    double weight;
    char sex;
    bool yz;

    name="li";
    age=19;
    weight=118.6;
    sex='m';
    yz= true;
    cout<<"name:"<<name<<" age:"<<age<<" weight:"<<weight<<" sex:"<<sex<<" uz"<<yz<<endl;
    //变量可以重复使用 bool实际内容是0和1而不是字符串false和true
    return 0;
}