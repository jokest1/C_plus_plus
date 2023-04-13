//
// Created by 36302 on 2023/3/29.
//

#ifndef CPP_LIST1_H
#define CPP_LIST1_H

#endif //CPP_LIST1_H
#include <assert.h>
#include <iostream>
namespace lt{
    template<class T>
            struct _base_node{
                typedef _base_node<T>* point;
                typedef T type;
                type date;
                point prev;
                point next;
                _base_node(const type& node=type())
                    :date(node)
                    ,prev(nullptr)
                    ,next(nullptr)
                    {}
            };

    template<class T>
            struct iterator{
                typedef T type;
                typedef T* point;
                typedef T& reference;
                typedef _base_node<T>* _node;
                typedef iterator<T> _self;
                _node node;
                iterator(_node node):node(node){}
                reference operator*(){
                    return this->node->date;
                }
                point operator->(){
                    return &(operator*());
                }
                _self& operator++(){
                    this->node= this->node->next;
                    return *this;
                }
                _self& operator--(){
                    this->node= this->node->prev;
                    return *this;
                }
                _self operator++(int){
                    _self temp= *this;
                    this->node= this->node->next;
                    return temp;
                }
                _self operator--(int){
                    _self temp= *this;
                    this->node= this->node->prev;
                    return temp;
                }
                bool operator!=(_self it){
                    return this->node!=it.node;
                }
                bool operator==(_self it){
                    return this->node==it.node;
                }
            };

    template<class T>
            class list{
            public:
                typedef T type;
                typedef iterator<T> iterator;
                typedef _base_node<T> node;
                list(){
                    head=new node();
                    head->next=head;
                    head->prev=head;
                }
                list(list<T>& it):list() {

                    for(auto i: it){
                        push_back(i);
                    }
                }
                list<T>& operator=(list<T>& it){
                    if(this!=head){
                        clear();
                        for (auto item:it) {
                            push_bacl(item);
                        }
                    }
                    return *this;
                }
                ~list(){
                    clear();
                    delete head;
                    head= nullptr;
                }
                void clear(){
                    auto b=begin();
                    while (b!=end()){
                        erase(b++);
                    }
                }
                bool empty(){
                    return begin()==end();
                }
                iterator begin(){
                    return iterator(head->next);
                }
                iterator end(){
                    return iterator(head);
                }
                void push_back(type x){
                    insert(--end(),x);
                }
                void push_front(type x){
                    insert(begin(),x);
                }
                void pop_back(){
                    erase(--end());
                }
                void pop_front(){
                    erase(begin());
                }
                void insert(iterator pos,type x){
                    node* cur=pos.node;
                    node* prev=cur->prev;
                    node* newNode=new node(x);
                    prev->next=newNode;
                    newNode->prev=prev;
                    cur->prev=newNode;
                    newNode->next=cur;
                }
                void erase(iterator pos){
                    assert(pos!=head);
                    node* cur=pos.node;
                    node* prev=cur->prev;
                    node* next=cur->next;
                    prev->next=next;
                    next->prev=prev;
                    delete cur;
                }
            private:
                node* head;
            };
    struct Date
    {
        int _year = 0;
        int _month = 1;
        int _day = 1;
    };
    void testlist1()
    {
        list<int> lt1;
        lt1.push_back(1);
        lt1.push_back(2);
        lt1.push_back(10);
        lt1.push_back(20);
        lt1.pop_back();
        list<int>::iterator it = lt1.begin();
        while (it != lt1.end())
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
    void testlist2()
    {
        list<Date> lt1;
        lt1.push_back(Date());
        lt1.push_back(Date());
        list<Date>::iterator it = lt1.begin();
        while (it != lt1.end())
        {
            /*std::cout << *it << " ";*/
            //it->Date->_year
            std::cout << it->_year << ":" << it->_month << ":" << it->_day << std::endl;
            std::cout << (*it)._year << ":" << (*it)._month << ":" << (*it)._day << std::endl;
            ++it;
        }
        //print_list(lt1);
    }
    void testlist3()
    {
        list<int> l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_back(4);

        list<int>l2(l1); //拷贝构造，用l1拷贝构造l2
        for (auto e : l1)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        for (auto e : l2)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

};