//
// Created by 36302 on 2023/4/14.
//
#include <iostream>
#include <cstring>

using namespace std;

class Test{
private:
    int *p;
public:
    Test(int *p) : p(nullptr) {
        p=new int[10];
    }
    Test(const Test& q){
        p=new int[10];
        memccpy((void *)p,(void *)&q.p,10, sizeof(int);
    }//浅拷贝是直接拷贝指针的指向并没有开辟空间,所以两个对象指向了同一片内存空间会使操作元素混乱
    //深拷贝通过开辟相同大小的内存空间并拷贝一份内存空间的数据来完成两份待操作数据
    ~Test(){
        if (p!= nullptr)
            delete[]p;
        p= nullptr;
    }
};
int main(){

    return 0;
}