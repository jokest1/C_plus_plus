//
// Created by 36302 on 2023/3/29.
//
#include <assert.h>
#include <iostream>
#ifndef CPP_LIST2_H
#define CPP_LIST2_H

#endif //CPP_LIST2_H
namespace lt{
    template<class T>
    struct _base_node{
//        结点含有向前的指针prev,向后的指针next和数据域data
        typedef _base_node<T>* point;
        typedef T type;
        point next;
        point prev;
        type data;
        _base_node(type data=type())
            : data(data)
            ,next(nullptr)
            ,prev(nullptr)
            {}
    };

    template<class T>
    struct iterator{
        typedef T type;
        typedef T *point;
        typedef T &reference;
        typedef _base_node<T> node;
        typedef iterator<T> _self;
        node* Node;

        iterator(node *node) : Node(node) {}
        reference operator*(){
            return (this->Node->data);
        }
        point operator->(){
            return &(operator*());
        }
        _self & operator++(){
            this->Node= this->Node->next;
            return *this;
        }
        _self &operator--(){
            this->Node= this->Node->prev;
            return *this;
        }
        _self operator++(int){
            _self temp= this->Node;
            this->Node=temp.Node->next;
            return temp;
        }
        _self operator--(int){
            _self temp= this->Node;
            this->Node=temp.Node->prev;
            return temp;
        }
        bool operator==(const _self & it){
            return this->Node==it.Node;
        }
        bool operator!=(const _self & it){
            return this->Node!=it.Node;
        }
    };

    template<class T>
    class list{
    public:
        typedef _base_node<T> node;
        typedef iterator<T> iterator;
    public:
        list(){
            head=new node();
            head->prev=head;
            head->next=head;
        }
        list(const list<T>& it): list(){
            for (auto item:it) {
                push_back(item);
            }
        }
        list<T>& operator=(const list<T> it){
            if(this!=it){
                clear();
                for (auto item: it) {
                    push_back(item);
                }
            }
        }
        void clear(){
            auto b=begin();
            while (b!=end()){
                erase(b++);
            }
        }
        iterator begin(){
            return iterator (head->next);
        }
        iterator end(){
            return iterator (head);
        }
        iterator begin()const{
            return iterator(head->next);
        }
        iterator end()const{
            return iterator(head);
        }
        void insert(iterator pos,T x){
            node* cur=pos.Node;
            node* prev=cur->prev;
            node * newNode=new node(x);
            newNode->prev=prev;
            prev->next=newNode;
            newNode->next=cur;
            cur->prev=newNode;
        }
        void erase(iterator pos){
            assert(pos!=head);
            node* cur=pos.Node;
            node* prev=cur->prev;
            node* next=cur->next;
            prev->next=next;
            next->prev=prev;
            delete cur;
        }
        ~list(){
            iterator be=begin();
            while (be!=end()){
                erase(be++);
            }
            delete head;
            head= nullptr;
        }
        void push_back(T x){
            insert(end(),x);
        }
        void push_front(T x){
            insert(begin(),x);
        }
        void pop_back(){
            erase(--end());
        }
        void pop_front(){
            erase(begin());
        }
    private:
        node* head;
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
    struct Date
    {
        int _year = 0;
        int _month = 1;
        int _day = 1;
    };

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
}