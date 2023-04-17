//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
/*
 * 路径或者网址过长可以将过长的字符串更加的规格化推出来R"(字符串)"
 */
int main(){
    char* path=R"(E:\study\study_code\CPP\0HelloWord.cpp)";//因为路径都已反斜杠划分所以为了避免转义字符的问题用R"(路径)"
    char* path2=R"(E:\study
                    \study_code
                    \CPP
                    \0HelloWord.cpp)";//同时还可以用原始字面量的方式使字符串的阅读性提高
    cout<<path<<endl;
    cout<<path2<<endl;
    return 0;
}