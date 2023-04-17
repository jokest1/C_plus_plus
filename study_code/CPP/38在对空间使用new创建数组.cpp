//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;

int main(){
//    使用new在堆区开辟连续内存空间然后保存好地址
    int *p=new int[10]();
    for(int i=0;i<10;++i){
        cout<<p[i]<<endl;
//        像正常数组一样使用
    }
    //用完后一定要用delete[]释放掉内存后将指针置空
    //如果连续delete[]同一片内存片会使程序崩溃
    delete[]p;
    p= nullptr;
}