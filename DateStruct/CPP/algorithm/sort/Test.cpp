//
// Created by 36302 on 2023/3/29.
//
#include "Sort.h"
#include <iostream>
#include <vector>
#include "TestSortPool.h"
using namespace std;

void test1();
int main(){
    test1();
    return 0;
}
void test1(){
    vector<int> arr;
    TestSortPool::randomArray(1,10000,8000,arr);
    lz::sort<int> tarr1(arr);
    lz::sort<int> tarr2(arr);
    lz::sort<int> tarr3(arr);
    lz::sort<int> tarr4(arr);
    lz::sort<int> tarr5(arr);
    tarr1.Bubble1();
    tarr2.Bubble2();
    tarr3.Bubble3();
    tarr4.Select1();
    tarr5.Heap();
};



