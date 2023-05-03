//
// Created by 36302 on 2023/4/30.
//
#include "../CPP/test_base.h"
#include "Sort.h"
#include "../ToolClass/TestTool.h"
int main(){
    vector<int> arr;
    tailSrcArrays(arr,10000,1,99999);
    Sort s1(arr);
    Sort s2(arr);
    Timer("冒泡排序",&s1,&Sort::BubbleSort1);
    Timer("冒泡排序",&s2,&Sort::BubbleSort2);
    return 0;
}