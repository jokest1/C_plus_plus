//
// Created by 36302 on 2023/4/6.
//

#ifndef STUDY_CODE_ABSTRACTLINE_H
#define STUDY_CODE_ABSTRACTLINE_H
#include "LineList.h"
#include <exception>
#include <iostream>
template<class T>
class abstractLine:public  Line<T>{
protected:
    int length;
    void rangeCheckIndex(int index) const {
        if(index<0||index>length){
            std::cout<<"index error"<<std::endl;
        }
    }
public:
    int size() override {
        return length;
    }

    bool empty() override {
        return length==0;
    }

    void push_back(T x) override {
        this->insert(length,x);
    }

    T pop_back() override {
        return this->erase(length-1);
    }

    bool contains(T x) const override {
        return this->indexOf(x)!=Line<T>::ELEMENT_NIT_EXIST;
    }
};
#endif //STUDY_CODE_ABSTRACTLINE_H
