//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * 字符型就是一个字节的整数代表字符
 * 不可显示的字符通过转义字符来表示
 */
int main(){
    cout<<"sizeof(char)"<< sizeof(char)<<endl;//字符型大小为1字节的整数类型
    char a='a'+3;//char作为整数亦可以参与运算
    cout<<a<<" "<<(int)a<<endl;//通过强制类型转换也可以从字符转为整数
    return 0;
}