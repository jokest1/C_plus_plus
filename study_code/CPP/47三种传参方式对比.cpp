//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;

struct node{
    char arr[30];
    int index;
};
void func1(node n){
    //值传递适合数据内存空间小且不需要修改原数据内容的情况
}
void func2(node* n){
    //指针传递适合传递占内存空间大又修改内存空间数据的情况
}
void func3(){
    //引用传递适合占内存空间大或传递常量或修改情况复杂
}
int main(){

    return 0;
}
