//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;
/*
 * C14对auto返回类型的优化使得不用再后置返回类型
 */
auto func(int i,int j){
    return i+j;
}
int main(){

    int i=10;
    int j=20;
    int sum=func(i,j);
    cout<<sum<<endl;
}
