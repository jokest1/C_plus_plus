//
// Created by 36302 on 2023/4/6.
//

#ifndef STUDY_CODE_LINELIST_H
#define STUDY_CODE_LINELIST_H


template<class T>
class Line{
public:
    const static int ELEMENT_NIT_EXIST=-1;
    virtual int size() =0;//返回元素数量
    virtual bool empty() =0;//判空
    virtual void clear() =0;//清空
    virtual void push_back(T x) = 0;//尾添加
    virtual void insert(int index,T x)=0;//随机添加元素
    virtual T pop_back()=0;//尾删除
    virtual T erase(int index)=0;//随机删除元素
    virtual T get(int index)const =0;//获取位置元素
    virtual bool contains(T x)const =0;//是否包含某个元素
    virtual int indexOf(T x)const =0;//某个元素索引位置
    virtual void set(int index,T x)=0;//修改某个位置
};
#endif //STUDY_CODE_LINELIST_H