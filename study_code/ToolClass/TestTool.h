//
// Created by 36302 on 2023/4/21.
//

#ifndef STUDY_CODE_TESTTOOL_H
#define STUDY_CODE_TESTTOOL_H
#include <iostream>
#include <chrono>
#include <string>

template<typename T>
void Timer(std::string name,T exe){
    auto start=std::chrono::steady_clock::now();
    exe();
    auto df=std::chrono::steady_clock::now()-start;
    std::cout<<name<<"运行时间: "<<df.count()<<"ns"<<std::endl;
}
/*
 * 调用类内成员函数要拿到具体的类指针和类内函数的偏移地址
 *  通过泛型函数模板,传递一个具体某个类的指针,然后传递函数在类内的便宜地址
 */
template<typename T>
void Timer(std::string name,T* obp, void(T::*fp)(void)){
    auto start=std::chrono::steady_clock::now();
    (obp->*fp)();
    auto df=std::chrono::steady_clock::now()-start;
    std::cout<<name<<"运行时间: "<<df.count()<<"ns"<<std::endl;
}
#endif //STUDY_CODE_TESTTOOL_H
