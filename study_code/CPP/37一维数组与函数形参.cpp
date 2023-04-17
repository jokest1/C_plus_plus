//
// Created by 36302 on 2023/4/13.
//
#include <iostream>

using namespace std;
//通过传递数组的首地址和数组元素的个数来进行操作
void print(int* p,int len){
    for(int i=0;i<len;++i){
        cout<<p[i]<<endl;
    }
}
int main(){
    int arr[10]{};
    print(arr,10);
    return 0;
}