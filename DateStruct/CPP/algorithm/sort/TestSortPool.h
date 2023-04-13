//
// Created by 36302 on 2023/4/1.
//

#ifndef CPP_TESTSORTPOOL_H
#define CPP_TESTSORTPOOL_H
#include <vector>
#include <stdlib.h>
#include <iostream>
struct TestSortPool {
    //给出最大值最小值和需要的数量,在给定的数组内生成数据
    static void randomArray(int min, int max, int size, std::vector<int>& arr);
    //给出最大值最小值和部分有序的数据数量
    static void tailSrcArray(int min,int max,int size,std::vector<int>& arr);
};


#endif //CPP_TESTSORTPOOL_H
