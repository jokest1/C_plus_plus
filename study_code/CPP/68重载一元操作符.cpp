//
// Created by 36302 on 2023/4/16.
//
#include <iostream>

using namespace std;
/*
 * 重载一元操作符前++和后++以形参中有无int来区分
 */
class Node{
public:
    int i;
    Node& operator++(){
        ++i;
        return *this;
    }
    Node operator++(int){
        Node temp= *this;
        ++*this;
        return temp;
    }
};
int main(){
    Node t;
    t.i=1;
    ++t;
    cout<<t.i<<endl;
    t++;
    cout<<t.i<<endl;
    return 0;
}