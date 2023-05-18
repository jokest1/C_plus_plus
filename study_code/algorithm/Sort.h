//
// Created by 36302 on 2023/4/30.
//

#ifndef STUDY_CODE_SORT_H
#define STUDY_CODE_SORT_H
#include "../CPP/test_base.h"

class Sort {
public:
    Sort(const vector<int> &arrs);
    void BubbleSort1();
    void BubbleSort2();
    void BubbleSort3();
    void selectSort();
private:
    vector<int> arrs;
};


#endif //STUDY_CODE_SORT_H
