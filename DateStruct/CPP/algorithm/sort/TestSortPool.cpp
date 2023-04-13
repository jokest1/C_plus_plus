//
// Created by 36302 on 2023/4/1.
//

#include "TestSortPool.h"
void TestSortPool::randomArray(int min,int max,int size,std::vector<int>& arr){
    int range=max-min;//确定随机数最大和最小的区间
    if (range>0){
        for (int i = 0; i < size; ++i) {
            //使用随机函数随机区间然后加入底数补正
            arr.push_back(std::rand()%range+min+1);
        }
    }else{
        std::cout<<"min大于了max"<<std::endl;
    }
}
void TestSortPool::tailSrcArray(int min,int max,int size,std::vector<int>& arr){
    int mid=max-size;
    randomArray(min,max,mid,arr);//调用随机填充函数
    for (int i = mid+1; i < max; ++i) {//将尾部有序的元素插入
        arr.push_back(i);
    }
}