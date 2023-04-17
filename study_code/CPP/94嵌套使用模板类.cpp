//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"

template<class T>
class Stack{
private:
    T* stack;
    int top;
    int size;
public:
    Stack(int size=3) : size(size),top(0) {
        stack=new T[size];
    }
    virtual ~Stack() {
        delete[] stack;
        stack= nullptr;
    }
    bool push(const T& x){
        if (top>=size)
            return false;
        stack[top++]=x;
    }
    bool pop(T& x){
        if (empty())
            return false;
        x=stack[--top];
    }
    bool empty(){
        return top==0;
    }
    T& operator[](int index){
        return stack[index];
    }
    const T& operator[](int index)const{
        return stack[index];
    }
    Stack& operator=(const Stack& temp){//深拷贝
        delete[] stack;
        size=temp.size;
        stack=new T[size];
        for (int i = 0; i < temp.size; ++i) {
            stack[i]=temp[i];
        }
        top=temp.top;
    }
};

template<class T>
class Vector{
private:
    T* vec;
    int size;
public:
    Vector( int size=2) :size(size) {
        vec=new T[size];
    }
    T& operator[](int index){
        if (index>=size)
            resize(size+10);
        return vec[index];
    }
    const T& operator[](int index)const{
        if (index>=size)
            resize(size+10);
        return vec[index];
    }
    void resize(int size){
        if (size< this->size)
            return;
        T* temp=new T[size];
        for (int i = 0; i < this->size; ++i) {
            temp[i]=vec[i];
        }
        delete[] vec;
        vec=temp;
        this->size=size;
    }
    int getSize(){
        return size;
    }
};
int main(){
    Vector<Vector<string>> vv;
    vv[0][0]="东1";
    vv[0][1]="东2";
    vv[0][2]="东3";
    vv[1][0]="西1";
    vv[1][1]="西2";
    vv[2][0]="南1";
    vv[2][1]="南2";
    vv[2][2]="南3";
    vv[2][3]="南3";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < vv[i].getSize(); ++j) {
            cout<<vv[i][j]<<"\t";
        }
        cout<<endl;
    }
}