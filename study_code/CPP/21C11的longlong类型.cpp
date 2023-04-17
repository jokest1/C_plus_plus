//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
using namespace std;
/*
 * long long是C11提供的更长的整数数据类型
 */
int main(){

    long l=2147483647+10;//数据截断
    long long ll=21474836480;//数据正常
    cout<<l<<endl;
    cout<<ll<<endl;
    cout<< sizeof(long long );
    return 0;
}