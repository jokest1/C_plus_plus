//
// Created by 36302 on 2023/4/13.
//
#include <fstream>
#include <iostream>
#include <string>

/*
*文本文件一般以行为单位进行组织,每个字节都有特殊意义
* 二进制文件以数据类型组织,每个字节没有意义要整体考虑
*/
using namespace std;
int main() {
    //多了一个枚举常量ios::binary来标记是二进制打开
    string load="../source/data.dat";
    ofstream fout(load);
    struct node{
        char sex[3];
        int age;
        char name[20];
    };
    node name1={"n",18,"nande"};
    node name2={"n",17,"nand"};
    node name3={"n",16,"nan"};
    fout.write(reinterpret_cast<const char *>(&name1), sizeof(name1));
    fout.write(reinterpret_cast<const char *>(&name2), sizeof(name2));
    fout.write(reinterpret_cast<const char *>(&name3), sizeof(name3));
    fout.close();
    return 0;
}
