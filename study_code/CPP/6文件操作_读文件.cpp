//
// Created by 36302 on 2023/4/13.
//
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string load="../source/test.txt";
    ifstream fin(load,ios::in);
    if (fin.is_open()== false){
        cout<<"打开文件失败\n"<<endl;
    }
    string temp;
    //第一种读取方法
    //通过string中的getline读取到一个string类型种
    while (getline(fin,temp)){
        cout<<temp<<"\n";
    }
    //第二种读取方法
    //通过对象内的getline函数读取到一个字符数组中
    char buffer[11];
    while(fin.getline(buffer,10)){
        cout<<buffer<<"\n";
    }
    //第三种方法
    while(fin>>temp){
        cout<<temp;
    }
    fin.close();
    return 0;
}