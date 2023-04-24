//
// Created by 36302 on 2023/4/18.
//
#include "test_base.h"
/*
 * map是封装了红黑树用于查找的容器
 * map中存储的元素以键值对pair<first,second>为单位
 */
int main(){
//    构造函数
//    map()创建一个空的map容器
    map<int,string> mm1;
//    map{}以初始化列表的方式创建一个map
    map<int,string>mm2={{1,"1"},{2,"2"},{3,"3"},{4,"4"}};
//    map(const map&)拷贝构造函数
    map<int,string>mm3(mm2);
//    map(begin,end)用迭代器初始化一个map
    map<int,string>mm4(mm3.begin(),mm3.end());

//    特性操作
//    size()元素数量 clear()清空 empty()判空
    cout<<"size(): "<<mm4.size()<<endl;
//    clear()清空元素数量
    mm4.clear();
    cout<<"clear()后: "<<mm4.size()<<endl;
//    empty()判空元素数量
    cout<<"empty()后: "<<mm4.empty()<<endl;

//    元素操作,map重载了[]运算符通过[key]开找到value
    mm2[2]="123456";
    for (auto& m:mm2) {
        cout<<m.first<<","<<m.second<<endl;
    }

//    查找和统计函数
//    find(k)->iterator返回指向这个k的迭代器
//    count(K)->int 返回这个k的个数
    cout<<"---------"<<endl;
    cout<<mm2.find(1)->first<<","<<mm2.find(1)->second<<endl;
    return 0;
}