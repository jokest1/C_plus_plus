//
// Created by 36302 on 2023/3/30.
//

#ifndef CPP_LIST3_H
#define CPP_LIST3_H

#endif //CPP_LIST3_H
#include <iostream>
#include <assert.h>
namespace lt{
    template<class T>
    struct _base_node{
        typedef _base_node<T>* point;
        typedef T type;
        point next;
        point prev;
        type data;

        _base_node(type data=type())
            : data(data)
            , next(nullptr)
            , prev(nullptr)
            {}
    };
    template<class T>
    struct iterator{
        typedef T type;
        typedef T &reference;
        typedef T *point;
        typedef iterator<T> _self;
        typedef _base_node<T>* node;

        node Node;//iterator存储指向结点的指针
        iterator(_base_node<T> *node) : Node(node) {}

        reference operator*(){//解引用返回的是引用
            return this->Node->data;
        }
        point operator->(){//箭头直接调用解引用后取地址返回指针
            return&(operator*());
        }
        _self &operator++(){//加加是向后挪动指针
            this->Node= this->Node->next;
            return *this;
        }
        _self operator--(){
            this->Node= this->Node->prev;
            return *this;
        }
        _self operator++(int){//后加加是返回自增前
            _self temp= this->Node;
            this->Node= this->Node->next;
            return temp;
        }
        _self operator--(int){
            _self temp= this->Node;
            this->Node= this->Node->prev;
            return temp;
        }
        bool operator==(const _self it){
            return this->Node==it.Node;
        }
        bool operator!=(const _self it){
            return this->Node!=it.Node;
        }
    };

    template<class T>
    class list{
    public:
        typedef iterator<T> iterator;
        typedef _base_node<T> node;
    public:
        list(){
            head=new node ();
            head->next=head;
            head->prev=head;
        }
        list(list& it):list(){
            for (auto item:it) {
                push_back(item);
            }
        }
        ~list(){
            clear();
            delete head;
            head= nullptr;
        }
        iterator begin(){
            return this->head->next;
        }//返回第一个元素的地址
        iterator end(){
            return this->head;
        }
        void clear(){
            auto be=begin();
            while (be!=end()){
                erase(be++);
            }
        }
        //删除迭代器指向的的元素
        void erase(iterator pos){
            assert(pos!=head);
            node * cur=pos.Node;
            node* prev=cur->prev;
            node* next=cur->next;
            prev->next=next;
            next->prev=prev;
            delete cur;
        }
        //插入函数,传递一个迭代器和一个要存储的数据
        void insert(iterator pos,T x){
            node* newNode=new node(x);
            node* cur=pos.Node;
            node* prev=cur->prev;
            prev->next=newNode;
            newNode->prev=prev;
            cur->prev=newNode;
            newNode->next=cur;
        }
        //push和pop操作全都建立在insert和erase的操作上
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
        //重写赋值清空后依次将数据压入
        list& operator=(const list<T>& it){
            clear();
            for (auto item:it) {
                push_back(item);
            }
        }
    private:
        node* head;
        //通过一个结点形成环状逻辑结构,头结点同样可以作为结束标志使用
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