//
// Created by 36302 on 2023/4/12.
//

#ifndef STUDY_CODE_CIRCLELINK_H
#define STUDY_CODE_CIRCLELINK_H
#include "LinkList.h"
template<class T>
class CircleLink:public LinkList<T>{
    void afterAdd(){
        auto node=this->findNode(this->length-1);
        node->next= this->head;
    }
};
#endif //STUDY_CODE_CIRCLELINK_H
