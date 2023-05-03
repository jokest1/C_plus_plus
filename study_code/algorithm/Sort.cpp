//
// Created by 36302 on 2023/4/30.
//

#include "Sort.h"

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
}

