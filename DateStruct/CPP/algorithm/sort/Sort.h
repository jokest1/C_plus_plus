//
// Created by 36302 on 2023/3/29.
//

#ifndef CPP_BUBBLESORT_H
#define CPP_BUBBLESORT_H

#endif //CPP_BUBBLESORT_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
namespace lz{
    template<class T>
    class sort{
    public:
        sort(const std::vector<T> &arr) : arr(arr) {}

        void  Bubble1(){
            auto start= clock();
            auto end=arr.size();
            for(;end>0;end--){
                for (int begin = 1; begin < end; ++begin) {
                    if (arr.at(begin)<arr.at(begin-1)){
                        std::swap(arr.at(begin),arr.at(begin-1));
                    }
                }
            }
            testTime(start,__func__);
        }
        void Bubble2(){
            auto start= clock();
            auto end=arr.size();
            for(;end>0;end--){
                //假如全部数据本就是有序,或者排列了一部分后有序,则需要提前结束
                bool flag= true;
                for (int begin = 1; begin < end; ++begin) {
                    if (arr.at(begin)<arr.at(begin-1)){
                        std::swap(arr.at(begin),arr.at(begin-1));
                        flag= false;
                        //如果有交换证明还是无序,设置标志位
                    }
                }
                //判断标志位
                if (flag) break;
            }
            testTime(start,__func__);
        }
        void Bubble3(){
            auto start=clock();
            int end=arr.size();
            int lastIndex=0;
            //准备好记录最后一次交换的位置
            for (;end>0;--end) {
                lastIndex=0;
                //初始化为0因为假如数据有序就需要直接结束循环,初始化为零就可实现这个情况
                for (int begin = 1; begin < end; ++begin) {
                    if (arr.at(begin)<arr.at(begin-1)){
                        std::swap(arr.at(begin),arr.at(begin-1));
                        lastIndex=begin+1;//记录最后一次交换的位置
                    }
                }
                end=lastIndex;//将最后一次交换的位置放入结束标志
            }
            testTime(start,__func__);
        }
        void Select1(){
            auto start=clock();
            int end=arr.size()-1;
            int max;
            for (; 0 < end; --end) {
                max=0;
                for (int begin = 1; begin <= end; ++begin) {
                    if (arr.at(max)<arr.at(begin)){
                        max=begin;
                    }
                }
                std::swap(arr[end],arr[max]);
            }
            testTime(start,__func__);
        }
        void Heap(){
            auto start=clock();
            auto temp=arr;
            std::make_heap(temp.begin(),temp.end());
            int end =arr.size()-1;
            for (; 0 <= end; --end) {
                arr[end]=temp.front();
                std::pop_heap(temp.begin(),temp.begin()+end);
            }
            testTime(start,__func__);
        }

        void Insert(){
            auto start=clock();
            for (int i = 1; i < arr.size(); ++i) {
                for (int j = i; j>0; ++j) {

                }
            }
            testTime(clock(),__func__ );
        }
        void merge(){

        }
        void testReal() {
            for (int i = 1; i < arr.size(); ++i) {
                if (arr[i-1]>arr[i]){
                    std::cout<<"\t"<<i<<"error!!!";
                    return;
                }
            }
            std::cout<<"\t"<<"right!!!";
        }

        void testTime(std::clock_t start, const char* cur) {
            auto end= clock();
            std::cout<<cur<<"    "<<"run time:"<<1000*(end-start)/CLOCKS_PER_SEC<<"ms";
            testReal();
            std::cout<<std::endl;
        }
    private:
        std::vector<T> arr;
    };
}