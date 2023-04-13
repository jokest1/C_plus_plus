//
// Created by 36302 on 2023/4/13.
//
#include <iostream>
void test1(int i){
    --i;
}
void test2(int *i){
    --(*i);
}
void test3(int &i){
    --i;
}
int main(){
    int i=10;
    test1(i);
    std::cout<<i<< std::endl;
    test2(&i);
    std::cout<<i<< std::endl;
    test3(i);
    std::cout<<i<< std::endl;
    //调用2和3之后i的内容发生了改变,指针和引用是特殊的传递方式会拿到原来的i并且可以修改内容
    return 0;
}