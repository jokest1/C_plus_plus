#include<iostream>
#include<assert.h>
#pragma once
//namespace yyw
//{
//    /**
//     * _list_node设计了最基础的结点结构
//     * 结点结构由两个指针prev和next,加上数据域data组成
//     * 构造函数由调用了元素的无参构造作为默认值,之后列表初始化
//     */
//    template<class T>
//    struct _list_node
//    {
//        _list_node<T>* _next;
//        _list_node<T>* _prev;
//        T _data;
//
//        _list_node(const T& val = T())
//                :_next(nullptr)
//                , _prev(nullptr)
//                , _data(val)
//        {}
//    };
//
//    /**
//     * 操纵元素的中间层iterator的设计,为了使算法和容器分离中间层承担了算法操作容器的责任
//     * 类型内由元素和元素的两种符合类型:元素的引用和元素的指针作为泛型元素
//     * iterator并不是长期贮存在list类中的,只有在调用迭代器函数时候才会临时创建出来
//     */
//    template<class T,class Ref,class Ptr>
//    struct _list_iterator
//    {
//        typedef _list_node<T> Node;
//        typedef _list_iterator<T, Ref, Ptr> Self;
//
//        Node* _node;
//
//        _list_iterator(Node* node)
//                :_node(node)
//        {}
//
//        /**
//         * 下方所有内容为所有的重写操作符,为了使iterator更像一个指针,必须具有所有的指针操作
//         */
//
//        //*it,返回_data *的语义是解引用所以返回的类型是一个引用类型
//        Ref operator*()
//        {
//            return _node->_data;
//        }
////        重写了->一定要重写*因为->会默认调用*操作符
//        //it->date ->的语义是访问某个结构体内部的成员所以返回的是一个指针
//        Ptr operator->()
//        {
//            return &_node->_data;
//        }
//
//
//        //it++,返回还是一个迭代器,前置加加
//        Self& operator++()
//        {
//            _node = _node->_next;
//            return *this;
//        }
//        //前置--
//        Self& operator--()
//        {
//            _node = _node->_prev;
//            return *this;
//        }
//        //后置加加
//        Self operator++(int)
//        {
//            Self tmp(*this);  //创建临时变量返回，后置加加，加加之前不变
//            //_list_iterator<T>tmp = *this;
//            _node = _node->_next;
//            //++（*this)
//            return tmp;
//        }
//        //后置减减
//        Self operator--(int)
//        {
//            Self tmp(*this);
//            _node = _node->_prev;
//            return tmp;
//        }
//
//        //==
//        bool operator ==(const Self& it)
//        {
//            return _node == it._node;
//        }
//        //it!=end()
//        bool operator!=(const Self& it)
//        {
//            return _node != it._node;
//        }
//    };
//    /**
//     * 通过一个头结点来控制整体的双向链表,实际构造是一个循环的链表通过头结点同时作为结束标志
//     * 内部提供的方法:
//     *  1.begin()
//     *  2.end()
//     *  3.无参构造
//     *  4.拷贝构造
//     *  5.重写=
//     *  6.析构
//     *  7.size()
//     *  8.empty
//     *  9.clear()
//     *  10.insert()
//     *  11.push_back()
//     *  12.pop_back()
//     *  13.push_front()
//     *  14.pop_front()
//     *  15.erase()
//     */
//    template<class T>
//    class list
//    {
//    public:
//        typedef _list_node<T> Node;
//    public:
//        typedef _list_iterator<T,T&,T*> iterator;
//        typedef _list_iterator<T,const T&,const T*> const_iterator;
////        list的实际内容只有一个头结点_head
//    private:
//        Node* _head;
//    public:
//        iterator begin()            //第一个数据的迭代器，节点的指针构建迭代器
//        {
//            return iterator(_head->_next);
//        }
//
//        iterator end()
//        {
//            return iterator(_head);
//        }
//
//        const_iterator begin() const
//        {
//            return const_iterator(_head->_next);
//        }
//        const_iterator end() const
//        {
//            return const_iterator(_head);
//        }
//
//        //带头双向循环链表
//        list()                      //list的构造
//        {
//            _head = new Node;
//            _head->_next = _head;
//            _head->_prev = _head;
//        }
//
//        //l2(l1)
//        list(const list<T>& l1)            //拷贝构造
//        {
//            //链表的最初状态
//            _head = new Node;
//            _head->_next = _head;
//            _head->_prev = _head;
//
//            //const_iterator it = l1.begin();   //构造一个const迭代器尾插到新的迭代器中
//            //while (it != l1.end())
//            //{
//            //	this->push_back(*it);
//            //	it++;
//            //}
//
//            for (auto e : l1)
//            {
//                push_back(e);
//            }
//        }
//
//        list<T>& operator=(const list<T>& l1)
//        {
//            if (this != &l1)
//            {
//                clear();
//                for (auto e : l1)
//                {
//                    push_back(e);
//                }
//            }
//            return *this;
//        }
//
//        //现代版的拷贝构造C++20版本
//        //list<T>& operator=(list<T> l1)
//        //{
//        //	swap(_head, l1._head);
//        //	return *this;
//        //}
//        void clear()
//        {
//            iterator it = begin();
//            while (it != end())
//            {
//                erase(it++);         //erase要自己单独实现出来
//            }
//        }
//        ~list()                      //析构函数
//        {
//            clear();                 //clear没有删除头结点
//            delete _head;
//            _head = nullptr;
//        }
//
//        size_t size()  const
//        {
//            return 0;
//        }
//        bool empty() const
//        {
//            return _head->_next == _head->_prev;
//        }
//        //T x  如果T类型是vector或者是string就造成了深拷贝,那么就得传引用，传引用不改变x就加const
//        void push_back(const T& x)
//        {
//            //Node* tail = _head->_prev;
//            //Node* newnode = new Node(x);
//
//            //tail->_next = newnode;
//            //newnode->_prev = tail;
//            //newnode->_next = _head;
//            //_head->_prev = newnode;
//            insert(end(), x);
//        }
//        void push_front(const T& x)
//        {
//            insert(begin(), x);
//        }
//        void insert(iterator pos, const T& x)    //在pos这个迭代器的前面插入一个节点
//        {
//            Node* newnode = new Node(x);
//            //pos 是个迭代器,而迭代器又是节点的指针，所以可以通过迭代器找到这个节点
//            Node* cur = pos._node;
//            Node* prev = cur->_prev;
//
//            prev->_next = newnode;
//            newnode->_prev = prev;
//            newnode->_next = cur;
//            cur->_prev = newnode;
//            //return iterator(newnode);
//        }
//
//        void pop_back()
//        {
//            erase(--end());
//        }
//        void pop_front()
//        {
//            erase(begin());//end是最后一个有效数据的下一个位置，所以end先减减，删除end减减的位置
//        }
//        void erase(iterator pos)
//        {
//            //pos是一个迭代器，节点的指针，可以找到这个节点
//            //找到要删除的节点del
//            assert(pos != end());//头结点不能删除
//            Node* del = pos._node;
//            //假设有1 2 3节点，要删除pos位置2节点，
//            //先2节点的前一个节点1节点的下一个节点指向2指向的3节点
//            //然后要把3和1链接起来，把3的前一个节点指向1，
//            //2的下一个节点3节点的前一个节点指向2的前一个节点
//            //删除2
//            del->_prev->_next = del->_next;
//            del->_next->_prev = del->_prev;
//            delete del;
//            //return iterator(next);//返回节点的下一个位置
//        }
//    };
//    void testlist1()
//    {
//        list<int> lt1;
//        lt1.push_back(1);
//        lt1.push_back(2);
//        lt1.push_back(10);
//        lt1.push_back(20);
//        lt1.pop_back();
//        list<int>::iterator it = lt1.begin();
//        while (it != lt1.end())
//        {
//            std::cout << *it << " ";
//            ++it;
//        }
//        std::cout << std::endl;
//    }
//    struct Date
//    {
//        int _year = 0;
//        int _month = 1;
//        int _day = 1;
//    };
//
//    void print_list(const list<int>& lt1)
//    {
//        list<int>::const_iterator it = lt1.begin();
//        while (it != lt1.end())
//        {
//            std::cout << *it << " ";
//            it++;
//        }
//        std::cout << std::endl;
//    }
//    void testlist2()
//    {
//        list<Date> lt1;
//        lt1.push_back(Date());
//        lt1.push_back(Date());
//        list<Date>::iterator it = lt1.begin();
//        while (it != lt1.end())
//        {
//            /*std::cout << *it << " ";*/
//            //it->Date->_year
//            std::cout << it->_year << ":" << it->_month << ":" << it->_day << std::endl;
//            std::cout << (*it)._year << ":" << (*it)._month << ":" << (*it)._day << std::endl;
//            ++it;
//        }
//        //print_list(lt1);
//    }
//    void testlist3()
//    {
//        list<int> l1;
//        l1.push_back(1);
//        l1.push_back(2);
//        l1.push_back(3);
//        l1.push_back(4);
//
//        list<int>l2(l1); //拷贝构造，用l1拷贝构造l2
//        for (auto e : l1)
//        {
//            std::cout << e << " ";
//        }
//        std::cout << std::endl;
//        for (auto e : l2)
//        {
//            std::cout << e << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//namespace test_list{
//    /**
//     *构建好基础结点
//     */
//    template<typename T>
//    struct _base_node{
//        typedef T _V_type;
//        typedef _base_node<T> _B_P;
//        _V_type data;
//        _B_P next;
//        _B_P prev;
//
//        _base_node(const _V_type data=_V_type())
//            : data(data)
//            , next(nullptr)
//            , prev(nullptr)
//            {}
//    };
//    /**
//     *
//     */
//    template<typename T>
//    struct _t_iterator{
//        typedef T value;
//        typedef T *pointer;
//        typedef T &reference;
//        typedef _base_node<T> _node;
//        typedef _t_iterator<T> _self;
//        _node node;
//
//        _t_iterator(const _node &node)
//            : node(node)
//            {}
//        reference operator*(){
//            return this->node.data;
//        }
//        pointer operator->(){
//            return &this->node.data;
//        }
//        _self operator++(){
//            return _self (this->node.next);
//        }
//        _self operator--(){
//            return _self (this->node.prev);
//        }
//        _self operator++(int){
//            _self temp(*this);
//            this=this->node.next;
//            return temp;
//        }
//        _self operator--(int){
//            _self temp(*this);
//            this=this->node.prev;
//            return temp;
//        }
//        bool operator==(const _self&  it){
//            return this->node==it.node;
//        }
//        bool operator!=(const _self&  it){
//            return this->node!=it.node;
//        }
//    };
//    /**
//     * 通过一个头结点来控制整体的双向链表,实际构造是一个循环的链表通过头结点同时作为结束标志
//     * 内部提供的方法:
//     *  1.begin()
//     *  2.end()
//     *  3.无参构造
//     *  4.拷贝构造
//     *  5.重写=
//     *  6.析构
//     *  7.size()
//     *  8.empty
//     *  9.clear()
//     *  10.insert()
//     *  11.push_back()
//     *  12.pop_back()
//     *  13.push_front()
//     *  14.pop_front()
//     *  15.erase()
//     */
//    template<typename T>
//    class _list{
//    public:
//        typedef T _value;
//        typedef _base_node<T> _node;
//        typedef _t_iterator<T> iterator;
//        typedef _t_iterator<T>& r_iterator;
//        typedef _t_iterator<T>& p_iterator;
//        typedef _t_iterator<const T> c_iterator;
//        typedef _t_iterator<const T>& c_r_iterator;
//        typedef _t_iterator<const T>& c_p_iterator;
//        iterator begin(){
//            return iterator (head->next);
//        }
//        iterator end(){
//            return head;
//        }
//    private:
//        _node* head;
//    };
//}
namespace test_list1{
    using namespace test_list1;
    template<class T>
    struct base_node{
        T data;
        base_node* next;
        base_node* prev;

        base_node(T data=T())
            : data(data)
            , next(nullptr)
            , prev(nullptr)
            {}
    };

    template<class T>
    struct iterator{
        typedef T type;
        typedef T* pointer;
        typedef T& reference;
        typedef const T* const_pointer;
        typedef const T& const_reference;
        typedef iterator<T> _self;
        base_node<T>* node;

        iterator(base_node<T> *node)
            : node(node)
            {}
        reference operator*(){
            return this->node->data;
        }
        pointer operator->(){
            return &(this->node->data);
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
            _self temp=*this;
            this->node=this->node->next;
            return temp;
        }
        _self operator--(int){
            _self temp=*this;
            this->node=this->node->prev;
            return temp;
        }
        bool operator==(const _self& it){
            return this->node==it.node;
        }
        bool operator!=(const _self& it){
            return this->node!=it.node;
        }
    };
    template<class T>
    class list{
    public:
        typedef base_node<T> node;
        typedef iterator<T> iterator;
    public:
        list() {
            head=new node();
            head->prev=head;
            head->next=head;
        }
        list(const list<T>& it) {
            head=new node();
            head->next=head;
            head->prev=head;
            for(auto i: it){
                push_back(i);
            }
        }
        ~list(){
            clear();
            delete head;
            head= nullptr;
        }
        size_t size(){
            return 0;
        }
        bool empty(){
            return head->next==head->prev;
        }
        void clear(){
            iterator begin=head->next;
            while (begin!=end()){
                erase(begin++);
            }
        }
        iterator begin(){
            return iterator(head->next);
        }
        iterator end(){
            return iterator(head);
        }
        iterator begin()const{
            return iterator(head->next);
        }
        iterator end()const{
            return iterator(head);
        }
        void insert(iterator index,const T& value){
            node * addNode=new node(value);
            node* cur=index.node;
            node* prev=cur->prev;
            prev->next=addNode;
            addNode->prev=prev;
            addNode->next=cur;
            cur->prev=addNode;
        }
        void erase(iterator index){
            assert(index!=head);
            node* delNode=index.node;
            delNode->prev->next=delNode->next;
            delNode->next->prev=delNode->prev;
            delete delNode;
        }
        void push_back(const T & value){
            insert(end(),value);
        }
        void push_front(const T& value){
            insert(begin(),value);
        }
        void pop_back(){
            erase(--end());
        }
        void pop_front(){
            erase(begin());
        }
        list<T>& operator=(const list<T> it){
            if (this!=it){
                clear();
                for (auto i:it) {
                    push_back(i);
                }
            }
            return *this;
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