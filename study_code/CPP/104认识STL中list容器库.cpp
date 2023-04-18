//
// Created by 36302 on 2023/4/18.
//
#include "test_base.h"
/*
 * list容器是双向链表,每个结点有两个指针指向前后结点
 * node{
 *      data;
 *      next;
 *      prev;
 * }
 *
 */
int main(){
//    构造函数
//  list()无参构造
    list<int> ll1;
//    list{}列表初始化
    list<int> ll2{1,2,3,4,5,6,7,8};
//    list(list&)拷贝初始化
    list<int> ll3(ll2);
//    list(begin(),end())迭代器初始化
    list<int> ll4(ll3.begin(),ll3.end());

//    特性操作
//    没有capacity(), 只有size() empty() clear() resize()

//      元素操作
//          因为是双鞋迭代器所以不提供随机访问

//      交换,反转,排序,对并
    ll3.swap(ll4);
    ll3.reverse();
    ll3.sort();
    ll3.merge(ll4);
    return 0;
}