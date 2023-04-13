//
// Created by 36302 on 2023/4/12.
//

#ifndef STUDY_CODE_QUEUE_H
#define STUDY_CODE_QUEUE_H
#include "Array.h"

template<class T>
class Dequeue{
protected:
    T* que;
    int capacity;
    int length;
    int head;
    int isIndex(int index){
        index+=head;
        if (index<0)
            index+=capacity;
        return index>=capacity?index-capacity:index;
    }
    void rangeCheckCapacity(){
        if(capacity<= this->length){
            int newCapacity=(capacity<<1);
            T* temp=new T[newCapacity];
            for (int i = 0; i < this->length; ++i) {
                temp[i]=que[isIndex(i)];
            }
            capacity=newCapacity;
            delete[] que;
            que=temp;
            head=0;
        }
    }
public:
    Dequeue(int capacity=10) : head(0), length(0) {
        int newCapacity=capacity>10?capacity:10;
        this->capacity=newCapacity;
        que=new T[newCapacity];
    }
    ~Dequeue(){
        clear();
        delete[] que;
        que= nullptr;
    }
    int size(){
        return length;
    }
    bool empty(){
        return length==0;
    }
    void clear(){
        head=0;
        length=0;
    }
    T front(){
        return que[isIndex(0)];
    }
    T back(){
        return que[isIndex(length-1)];
    }
    void push_back(T x){
        rangeCheckCapacity();
        que[isIndex(length++)]=x;
    }
    void push_front(T x){
        rangeCheckCapacity();
        que[isIndex(-1)]=x;
        length++;
        if (--head<0){
            head+=capacity;
        }
    }
    T pop_back(){
        T old=back();
        length--;
        return old;
    }
    T pop_front(){
        T old=front();
        head++;
        length--;
        return old;
    }
};
#endif //STUDY_CODE_QUEUE_H