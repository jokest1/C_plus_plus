//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
int compare(const void* e1,const void* e2){
    if(*((int*)e1)<*((int*)e2))return -1;
    else if(*((int*)e1)>*((int*)e2))return 1;
    return 0;
}
int main(){
    int a[10]={19,20,3,1,4,67,89,34,8,23};
    qsort(a,10, sizeof(int ),compare);
//    qsort函数传入:首地址,元素数量,元素大小,回调函数后可以进行排序
    for (int i = 0; i < 10; ++i) {
        cout<<a[i]<<",";
    }
}