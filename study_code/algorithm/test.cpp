//
// Created by 36302 on 2023/4/30.
//
#include "../CPP/test_base.h"
#include "Sort.h"
#include "../ToolClass/TestTool.h"
int main(){
    vector<int> arr;
    randomArrays(arr,20000,1,99999);
    Sort s1(arr);
    Sort s2(arr);
    Sort s3(arr);
    Sort s4(arr);
    Timer("冒泡排序1",s1,&Sort::BubbleSort1);
    Timer("冒泡排序2",s2,&Sort::BubbleSort2);
    Timer("冒泡排序3",s3,&Sort::BubbleSort3);
    Timer("选择排序",s4,&Sort::selectSort);

    return 0;
}