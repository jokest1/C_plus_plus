//
// Created by 36302 on 2023/3/30.
//

#include <iostream>

#ifndef CPP_VECTOR_H
#define CPP_VECTOR_H

#endif //CPP_VECTOR_H
namespace lz{
    template<class T>
    class vector{
    public://因为是随机存储的容器可以使用指针来直接充当迭代器
        typedef T* iterator;
        typedef T type;

        void insert(iterator pInt, int i) {
            if(size()+1>=capacity()){
                resize((capacity()>0?capacity():1)*2<<1);
            }
            auto e=end();
            for (; e >pInt ; --e) {
                *e=*(e-1);
            }
            *pInt=i;
            ++finish;
        }

        void erase(iterator pInt) {
            auto e=end()-1;
            for (;pInt<e;pInt++) {
                *pInt=*(pInt+1);
            }
            --finish;
        }

    public:
        //无参构造直接全部设为空指针
        vector():start(nullptr)
            ,finish(nullptr)
            ,strong_of_end(nullptr)
            {}

        vector(int size){
            start=new type [size];
            finish=start;
            strong_of_end=start+size;
        }
        iterator begin(){
            return start;
        }
        iterator end(){
            return finish;
        }
        int capacity(){
            return strong_of_end-start;
        }
        void resize(int n){
            if(n>capacity()){
                int oldsize=size();
                vector<T>temp(n);
                for (auto item:*this) {
                    temp.push_back(item);
                }
                delete[] this->start;
                start=temp.start;
                finish=temp.start+oldsize;
                strong_of_end=temp.start+n;
            }
        }
        int size(){
            return finish-start;
        }
        bool empty(){
            return (start==finish);
        }
        type& operator[](int index){
            return (start[index]);
        }
        type at(int index){
            return operator[](index);
        }
        void push_back(type x){
            if(size()+1>=capacity()){
                resize((capacity()>0?capacity():1)*2);
            }
            *finish++=x;
        }
        void pop_back(){
            --finish;
        }
        void clear(){
            delete[] start;
            start=finish=strong_of_end= nullptr;
        }
    private:
        iterator start;//指向内存片开始位置
        iterator finish;//直线最后一个元素后一个位置
        iterator strong_of_end;//指向内存片结束位置
    };
    void testvector1()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.pop_back();
        vector<int>::iterator it = v1.begin();
        while (it != v1.end())
        {
            //*it += 1;
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
        {
            v1[i] = 1;
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl;
        for (auto& e : v1)          //支持迭代器就支持范围for
        {
            e -= 1;
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    void testvector2()
    {
        vector<int> v2;     //const对象的vector
        vector<int>::iterator vit = v2.begin();
        while (vit != v2.end())
        {
            //*vit += 1;
            std::cout << *vit << " ";
        }
        std::cout << std::endl;
    }
    void testvector3()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.insert(v1.begin() + 1, 10);
        v1.erase(v1.begin() + 1);
        for (auto e : v1)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    void testvector4()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(6);

        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
        v1.resize(10);
        for (auto& e : v1)          //支持迭代器就支持范围for
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;

        v1.resize(12);
        for (auto& e : v1)          //支持迭代器就支持范围for
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
    }
    void testvector5()
    {
        vector<int> v1;
        v1.push_back(10);
        v1.push_back(9);
        v1.push_back(8);
        v1.push_back(7);
        v1.push_back(6);
        vector<int>v2(v1);
        for (auto& e : v1)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        for (auto& e : v2)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        vector<int> v3;
        v3 = v1;
        for (auto& e : v2)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}
