//
// Created by 36302 on 2023/4/11.
//

#ifndef STUDY_CODE_LINKLIST_H
#define STUDY_CODE_LINKLIST_H
#include "abstractLine.h"

template<class T>
class LinkList:public abstractLine<T>{
protected:
    struct base_node{
        T data;
        base_node* next;
        base_node(T data, base_node *next) : data(data), next(next) {}
    };
    base_node * findNode(int index) const {
        auto node=head;
        while (index--){
            node=node->next;
        }
        return node;
    }
    base_node * findNode(int index) {
        auto node=head;
        while (index--){
            node=node->next;
        }
        return node;
    }
    base_node* head;
    virtual void afterAdd(){};
public:
    ~LinkList(){
        clear();
    }
    void clear() override {
        if (head!= nullptr){
            while (head){
                erase(0);
            }
        }
        this->length=0;
    }

    void insert(int index, T x) override {
        if (index==0){
            this->head=new base_node(x, this->head);
            afterAdd();
        }else{
            auto node= findNode(index-1);
            node->next=new base_node(x,node->next);
            if(index== this->length)
                afterAdd();
        }
        ++this->length;
    }

    T erase(int index) override {
        T old;
        if (index==0){
            auto node=head;
            old=head->data;
            head=head->next;
            delete node;
            node= nullptr;
            afterAdd();
        }else{
            auto node= findNode(index-1);
            auto next=node->next;
            old=next->data;
            node->next=next->next;
            delete next;
            next= nullptr;
            if(index== this->length-1)
                afterAdd();
        }
        --this->length;
        return old;
    }

    T get(int index) const override {
        return findNode(index)->data;
    }

    int indexOf(T x) const override {
        auto node=head;
        for (int i = 0; i < this->length; ++i,node=node->next) {
            if (x==node->data)
                return i;
        }
        return Line<T>::ELEMENT_NIT_EXIST;
    }

    void set(int index, T x) override {
        findNode(index)->data=x;
    }
};
#endif //STUDY_CODE_LINKLIST_H
