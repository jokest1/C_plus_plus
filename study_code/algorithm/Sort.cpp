//
// Created by 36302 on 2023/4/30.
//

#include "Sort.h"
#include "../ToolClass/TestTool.h"

Sort::Sort(const vector<int> &arrs)
        : arrs(arrs){}
void Sort::BubbleSort1(){
    for (int end = arrs.size(); end >0 ;--end) {
        for (int begin = 1; begin < end; ++begin) {
            if (arrs[begin]<arrs[begin-1]){
                swap(arrs[begin],arrs[begin-1]);
            }
        }
    }
    testRight(arrs);
}
void Sort::BubbleSort2(){
    for (int end = arrs.size(); end >0 ;--end) {
        bool flag= true;
        for (int begin = 1; begin < end; ++begin) {
            if (arrs[begin]<arrs[begin-1]){
                swap(arrs[begin],arrs[begin-1]);
                flag= false;
            }
        }
        if (flag)break;
    }
    testRight(arrs);
}
void Sort::BubbleSort3(){
    int last=0;
    for (int end = arrs.size(); end >0 ; --end) {
        last=end;
        for(int begin=1;begin<end;++begin){
            if(arrs[begin]<arrs[begin-1]){
                swap(arrs[begin],arrs[begin-1]);
                last=begin+1;
            }
        }
        end=last;
    }
    testRight(arrs);
}
void Sort::selectSort(){
    //选择排序
    int maxIndex=0;
    int end=arrs.size();
    while (--end){
        maxIndex=0;
        for(int index=0;index<=end;++index){
            if (arrs[index]>=arrs[maxIndex]){
                swap(index,maxIndex);
            }
        }
        swap(arrs[end],arrs[maxIndex]);
    }
    testRight(arrs);
}


