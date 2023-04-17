//
// Created by 36302 on 2023/4/16.
//
#include <iostream>

using namespace std;
/*
 * new和delete运算符内部使用了C语言的free和malloc
 * 如果类内没有重写new和delete则调用全局如果内部重载了则调用类内重载
 */
class testMalloc{
private:

public:
    int a;
    testMalloc(int a) : a(a) {}

    void* operator new(size_t size){
        cout<<"调用了内部new函数"<<endl;
        return malloc(size);
    }
    void operator delete(void* ptr){
        cout<<"调用了内部delete函数"<<endl;
        if(ptr== nullptr)return ;
        free(ptr);
    }
};
void* operator new(size_t size){
    cout<<"调用了全局new函数"<<endl;
    return malloc(size);
}
void operator delete(void* ptr){
    cout<<"调用了全局delete函数"<<endl;
    if(ptr== nullptr)return ;
    free(ptr);
}
int main(){
    int* p=new int(8);
    cout<<"*p:"<<*p<<endl;
    delete p;
    testMalloc *q=new testMalloc(9);
    cout<<"a:"<<q->a<<endl;
    delete q;
    return 0;
}