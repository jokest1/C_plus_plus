//
// Created by 36302 on 2023/4/27.
//
#include "test_base.h"
/*
 * 在C++之前使用0和NULL两个数值来代表空指针,但是使用数值去代表指针类型语法上并不明确
 * 在语义上并不明确的数据类型在调用的时候容易出现歧义
 * nullptr具体类型为nullptr_t类型
 */
void test1(int i,int ii){
    cout<<"调用了int,int"<<endl;
}
void test1(int i,void* v){
    cout<<"调用了int,point"<<endl;
}

int main(){
//    test1(10,NULL);//重载出现歧义不知道调用哪个重载
    test1(10, nullptr);//歧义消失调用重载int ,void*
    auto v= nullptr;
    cout<<boost::typeindex::type_id_with_cvr<decltype(v)>().pretty_name()<<endl;
    return 0;
}