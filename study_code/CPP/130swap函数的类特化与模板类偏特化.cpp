//
// Created by 36302 on 2023/4/23.
//
#include "test_base.h"
/*
 * swap函数是一个很重要的功能,在class可以进行相互copy行为的时候要考虑设计这个函数
 * 虽然std内有swap但是通过调用copy和=进行统一实现的,对于通过指针管理的一片资源的class来说效率低下考虑重写
 * 具体的class在内部写一个swap成员函数之后在std空间内写一个特化版本的swap,注意:内部写一下using std::wap
 */
class testSwap{
public:
    testSwap(int length=10) : arr(new int[10]) {}
    testSwap(const testSwap& rm){
        cout<<"调用了copy构造"<<endl;
    }
    testSwap& operator=(const testSwap& rm){
        cout<<"调用了copy赋值"<<endl;
    }
    ~testSwap(){
        if (arr){
            delete[]arr;
            arr= nullptr;
        }
    }
    void swap(testSwap& temp){
        //完成了成员swap
        auto tp=temp.arr;
        temp.arr=arr;
        arr=tp;
    }
private:
    int* arr;
};

namespace std{
template<>
void swap(testSwap &t1, testSwap &t2) {
    cout<<"调用了偏特化swap"<<endl;
    using std::swap;
    t1.swap(t2);
}

}
int main(){
    testSwap ts1;
    testSwap ts2;
    std::swap(ts1,ts2);//系统提供的swap通过调用copy和=进行交换
    return 0;
}