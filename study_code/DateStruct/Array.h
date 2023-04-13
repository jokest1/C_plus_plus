//
// Created by 36302 on 2023/4/6.
//

#ifndef STUDY_CODE_ARRAY_H
#define STUDY_CODE_ARRAY_H
#include "abstractLine.h"

template<class T>
class DynamicArray:public abstractLine<T>{
private:
    const static int DEFAULT_CAPACITY=10;
    int Capacity;
    T* arr;
    void rangeCheckCapacity(){
        if(Capacity<= this->length){
            int newCapacity=(Capacity<<1);
            T* temp=new T[newCapacity];
            for (int i = 0; i < this->length; ++i) {
                temp[i]=arr[i];
            }
            Capacity=newCapacity;
            delete[] arr;
            arr=temp;
        }
    }
public:
    DynamicArray(): DynamicArray(DEFAULT_CAPACITY) {}
    DynamicArray(int capacity) {
        Capacity=(capacity>DEFAULT_CAPACITY?capacity:DEFAULT_CAPACITY);
        arr=new T[Capacity];
        this->length=0;
    }

    virtual ~DynamicArray() {
        clear();
        delete[] arr;
        arr= nullptr;
    }
    void clear() override {
        this->length=0;
    }
    void insert(int index, T x) override {
        this->rangeCheckIndex(index);
        rangeCheckCapacity();
        for (int i = this->length; i >index ; --i) {
            arr[i]=arr[i-1];
        }
        arr[index]=x;
        ++this->length;
    }

    T erase(int index) override {
        auto old= arr[index];
        --this->length;
        for (int i = index; i > this->length ; ++i) {
            arr[i]=arr[i+1];
        }
        return old;
    }

    T get(int index) const override {
        this->rangeCheckIndex(index);
        return arr[index];
    }

    int indexOf(T x) const override {
        for (int i = 0; i < this->length; ++i) {
            if  (arr[i]==x)
                return i;
        }
        return Line<T>::ELEMENT_NIT_EXIST;
    }
    void set(int index,T x){
        this->rangeCheckIndex(index);
        arr[index]=x;
    }

    int getCapacity() const {
        return Capacity;
    }
};
#endif //STUDY_CODE_ARRAY_H
