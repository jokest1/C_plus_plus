//
// Created by 36302 on 2023/4/27.
//
#include "test_base.h"
/*
 * enum 是全局使用的可以在enum class 修饰符:自定义类型 {}进行限定,不再是全局枚举
 * 同时也可以使用枚举充当索引
 * 也可以自定义枚举代表的类型
 */
enum class enumtest:char{
    A='A',
    B='B',
    C='C',
    D='D',
    E='E'
};
int main(){
    cout << static_cast<char>(enumtest::A) << endl;
    return 0;
}