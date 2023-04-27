//
// Created by 36302 on 2023/4/26.
//
#include "test_base.h"
/*
 * C14允许返回类型为auto类型但是要用后缀类型指出具体类型
 * 后缀具体类型可以根据形参进行推断使用关键字decltype()
 * auto作为返回值无法返回可变参数,可以使用decltype(auto)后缀表示使用auto规则
 */

template<typename T>
auto at(T t1,int index)-> decltype(t1[index]){
    return t1[index];
}

//auto at1()->decltype(auto) {
//    return {1,2,3};
//}
int main(){
    return 0;
}