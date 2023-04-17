//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
int main(){
    int ii[10]{};
    int * p=ii;
    for (int i = 0; i < 10; ++i) {
        cout<<"&ii["<<i<<"]="<<&ii[i]<<"|"<<"(p+"<<i<<")="<<(p+i)<<endl;;
        //数组是内存片的首地址,通过[索引]解释为首地址+偏移量后解引用
    }
}