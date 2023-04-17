//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
/*
 * 增加了else if和else 增加了可选择的分支数量
 */
using namespace std;
int main(){
//    bool flag= true;
    bool flag= false;
    if(flag){
        cout<<"true";
    }else{
//        只有在存在if语句后才能使用else表示条件不成立执行的代码
        cout<<"false";
    }

    return 0;
}