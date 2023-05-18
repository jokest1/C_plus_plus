//
// Created by 36302 on 2023/4/21.
//

#ifndef STUDY_CODE_TESTTOOL_H
#define STUDY_CODE_TESTTOOL_H
#include <iostream>
#include <chrono>
#include <string>
#include <random>
/*
 * 调用类内成员函数要拿到具体的类指针和类内这个成员函数的地址
 *  通过泛型函数模板,传递一个具体某个类的指针,然后传递函数在全局的地址
 */
template<typename T>
void Timer(std::string name,T& obp, void(T::*fp)(void)){
    auto start=std::chrono::system_clock::now();
    (obp.*fp)();
    auto df=std::chrono::system_clock::now()-start;
    std::cout<<name<<"运行时间: "<<double (df.count())*
                    std::chrono::microseconds::period ::num
                    /std::chrono::microseconds ::period ::den
                    <<"ms"<<std::endl;
}
template<typename T>
void randomArrays(T& list,int size,int min,int max){
    int range=max-min;
    while (size--){
        list.push_back(rand()%range+1);
    }
}
template<typename T>
void tailSrcArrays(T& list,int size,int min,int max){
    int mid=max-size;
    randomArrays(list,max-mid,min,mid);//调用随机填充函数
    for (int i = mid+1; i < max; ++i) {//将尾部有序的元素插入
        list.push_back(i);
    }
}
template<typename T>
void testRight(T& list){
    //检验排序的正确性
    for (int i = 1; i < list.size(); ++i) {
        if (list.at(i)<list.at(i-1)){
            std::cout<<"排序不正确"<<std::endl;
            break;
        }
    }
}
#endif //STUDY_CODE_TESTTOOL_H
