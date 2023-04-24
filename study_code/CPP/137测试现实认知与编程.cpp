//
// Created by 36302 on 2023/4/24.
//
#include "test_base.h"
//长与宽不再相等不再是一个正方形,正方形直接继承矩形在编程中会出现与现实相矛盾的现象
//在编程中不要主观使用现实的认知
class rectangle{
    //一个矩形类记录长宽,可以修改矩形的长宽
public:
    rectangle(int wide, int high) : wide(wide), high(high) {}
    void setWide(int wide) {
        rectangle::wide = wide;
    }
    void setHigh(int high) {
        rectangle::high = high;
    }
    void print(){
        cout<<"长:"<<wide<<" 宽:"<<high<<endl;
    }
private:
    int wide;
    int high;
};
class square:public rectangle{
    //一个正方形继承自矩形,认知中矩形包含正方形
public:
    square(int wide) : rectangle(wide, wide) {}
};
int main(){
    rectangle rg(20,30);
    square sq(10);
    rg.print();
    sq.print();
    rg.setHigh(20);
    sq.setHigh(15);
    rg.print();
    sq.print();
    return 0;
}