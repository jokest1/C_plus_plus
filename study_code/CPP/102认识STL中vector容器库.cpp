//
// Created by 36302 on 2023/4/18.
//
#include "test_base.h"
/*
 * vector内封装了动态数组
 * 内部用三个指针来维护一片内存空间
 */
int main(){
//    构造函数
//  vector() 无参构造函数
    vector<int> vv1;
    cout<<"实际容量是: "<<vv1.capacity()<<"数据量是: "<<vv1.size()<<endl;
//    列表初始化{}
    vector<int> vv2{1,2,3,4,5,6,7,8,9};
    cout<<"实际容量是: "<<vv2.capacity()<<"数据量是: "<<vv2.size()<<endl;
//    拷贝构造vector(const vectro& v)
    vector<int> vv3(vv2);
    cout<<"实际容量是: "<<vv3.capacity()<<"数据量是: "<<vv3.size()<<endl;
//  迭代器构造 vector(begin,end)
    vector<int> vv4(vv3.begin(),vv3.end());
    cout<<"实际容量是: "<<vv4.capacity()<<"数据量是: "<<vv4.size()<<endl;

//   特性操作
//    size()/capaticy()/clear()/empty() 数据个数/容器大小/清空/判空是通用的
//      resever(n)至少保证n个空间  resize(n) 将将容量更为n只修改end_of_strong的指针内容
    vv4.resize(2);
    cout<<"实际容量是: "<<vv4.capacity()<<"数据量是: "<<vv4.size()<<" "<<vv4[3]<<endl;

//   元素操作
//    重载了下标运算符[]
    cout<<"index:2: "<<vv4[2]<<endl;
//    查看头尾元素back()尾 front()头
    cout<<"back: "<<vv4.back()<<"  front: "<<vv4.front()<<endl;

//    超载了赋值操作符可以使用vector或者列表初始化来进行赋值操作
    vv4=vv3;
    vv4={1,2,3,4,5,6,7,8};

//    比较操作和交换与string相同

//  插入和删除操作
    vv4.push_back(9);//尾部插入
    vv4.emplace_back(10);//同样是尾部插入,可以在传参时候直接进行构造效率比push_back快
    vv4.erase(vv4.begin());//删除迭代器位置的元素同时返回下一个有效的迭代器
    return 0;
}