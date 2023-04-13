//
// Created by 36302 on 2023/4/12.
//

#ifndef STUDY_CODE_STACK_H
#define STUDY_CODE_STACK_H
#include "Array.h"

template<class T>
class stack{
protected:
    DynamicArray<T> sta;
public:
    void push(T x){
        sta.push_back(x);
    }
    T pop(){
        return sta.pop_back();
    }
    int size(){
        return sta.size();
    }
    void clear(){
        sta.clear();
    }
    bool empty(){
        return sta.empty();
    }
    T stackTop(){
        return sta.get(sta.size()-1);
    }
};
#endif //STUDY_CODE_STACK_H