//
// Created by 36302 on 2023/4/13.
//
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
int main(){
    string load="../source/test.txt";//定义打开路径
    ofstream fout;//创建文件输出流对象
    //这里也有带参数的构造函数fout(load)可以省略open的操作
    //文件还有打开模式分为三种:ios::out,ios::in,ios::app


    fout.open(load,ios::app);//通过open方法打开指定路径不存在就创建,存在就打开
//    fout.open(load,ios::out);
//    fout.open(load,ios::in);
    fout<<"22222\n";//写入数据
    fout<<"22222\n";
    fout<<"22222\n";
    //关闭文件,fout对象失效前会自动调用close();
    fout.close();
    return 0;
}
