//
// Created by 36302 on 2023/4/12.
//

#ifndef STUDY_CODE_DOUBLELINKLIST_H
#define STUDY_CODE_DOUBLELINKLIST_H
#include "abstractLine.h"
template<class T>
class DoubleLinkList:public abstractLine<T>{
protected:
    struct Double_Base_Node{
        T element;
        Double_Base_Node* next;
        Double_Base_Node* prev;

        Double_Base_Node(Double_Base_Node *prev,T element, Double_Base_Node *next)
                : element(element), next(next),prev(prev) {}
    };
    Double_Base_Node* head;
    Double_Base_Node* tail;
    Double_Base_Node* findNode(int index){
        this->rangeCheckIndex(index);
        if(index<=(this->length<<1)){
            auto node=head;
            while (index--){
                node=node->next;
            }
            return node;
        }else{
            auto node=tail;
            int temp= this->length-index-1;
            while (temp--){
                node=node->prev;
            }
            return node;
        }
    }
    Double_Base_Node* findNode(int index)const{
        this->rangeCheckIndex(index);
        if(index<=(this->length<<1)){
            auto node=head;
            while (index--){
                node=node->next;
            }
            return node;
        }else{
            auto node=tail;
            int temp= this->length-index-1;
            while (temp--){
                node=node->prev;
            }
            return node;
        }
    }
    void afterAdd(){

    }
public:
    virtual ~DoubleLinkList() {
        clear();
    }

    void clear() override {
        auto node =head;
        auto next=head;
        while (node!= nullptr){
            next=node->next;
            delete node;
        }
        head= nullptr;
        tail= nullptr;
        this->length=0;
    }

    void insert(int index, T x) override {
        if (this->length==0){
            head=new Double_Base_Node(nullptr,x, nullptr);
            tail=head;
            afterAdd();
        } else if(index==0){
            head->prev=new Double_Base_Node(nullptr,x,head);
            head=head->prev;
            afterAdd();

        }else if(index== this->length){
            tail->next=new Double_Base_Node(tail,x, nullptr);
            tail=tail->next;
            afterAdd();

        }else{
            auto node= findNode(index-1);
            auto next=node->next;
            node->next=new Double_Base_Node(node,x,next);
            next->prev=node->next;
        }
        this->length++;
    }

    T erase(int index) override {
        T old;
        if(this->length==1){
            old=head->element;
            delete head;
            head=tail= nullptr;
        }else if (index==0){
            old=head->element;
            auto temp=head;
            head=head->next;
            head->prev= nullptr;
            delete temp;
            afterAdd();
        }else if(index== this->length-1){
            old=tail->element;
            auto temp=tail;
            tail=tail->prev;
            tail->next= nullptr;
            delete temp;
            afterAdd();
        } else{
            auto node= findNode(index);
            old=node->element;
            auto prev=node->prev;
            auto next=node->next;
            prev->next=node;
            next->prev=prev;
            delete node;
        }
        this->length--;
        return old;
    }

    T get(int index) const override {
        return findNode(index)->element;
    }

    int indexOf(T x) const override {
        auto node=head;
        for (int i = 0; i < this->length; ++i,node=node->next) {
            if (node->element==x)
                return i;
        }
        return Line<T>::ELEMENT_NIT_EXIST;
    }

    void set(int index, T x) override {
        findNode(index)->element=x;
    }
};
#endif //STUDY_CODE_DOUBLELINKLIST_H


