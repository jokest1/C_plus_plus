//
// Created by 36302 on 2023/4/13.
//
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
struct node{
    char sex[3];
    int age;
    char name[20];
};

int main(){
    string load="../source/data.dat";
    ifstream fin(load,ios::binary);
    node girl;
    //读取的时候要保证结构体内全都是基本数据类型
    fin.read((char*)&girl, sizeof(node));
    cout<<girl.sex<<","<<girl.age<<","<<girl.name<<endl;
    fin.close();
    return 0;
}