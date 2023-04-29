//
// Created by 36302 on 2023/4/28.
//
#include "test_base.h"
/*
 * 新增了constexpr修饰符用于修饰函数和对象,意图表达结果在编译期间已知
 * 对于constexpr函数使得应用地方更加广泛,如需要常量的地方可以通过constexpr函数计算
 * constexpr有两种性质:1如果传入运行期参数正常返回运行期的计算结果;2传入编译器参数则返回编译期的值
 */

constexpr int size(int i){
    return i*2;
}
int main(){
    int i;
    cin>>i;
//    array<int,size(i)> aci;//i不是编译期初始化值,所以constexpr返回运行期值,编译不通过
    array<int ,size(10)> acc;//10是编译期值已知,所以constexpr返回编译器已知值,编译通过
    return 0;
}