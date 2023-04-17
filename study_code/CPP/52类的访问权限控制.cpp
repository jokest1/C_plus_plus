//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;

class node{
private:
    int ii;
    int jj;
    int kk;
public:
    void initNode(int i,int j, int k){
        ii=i;
        jj=j;
        kk=k;
    }
};
int main(){
    node n1;
    n1.initNode(1,2,3);//这里可以方位这个方法因为修饰是public是共有的
//    n1.ii;这里无法访问类内的ii变量因为修饰符为private私有的
    return 0;
}