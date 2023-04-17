//
// Created by 36302 on 2023/4/14.
//
#include <iostream>

using namespace std;
//第一种方式:
class boy;//首先提前定义类
class girl{
    friend boy; //在类内声明友元
private:
    int no=1;
    int h=1;
};
class boy{
public://之后就可以直接调用了
    void func1(const girl& g){cout<<__func__ <<","<<g.no<<","<<g.h<<endl;};
};

//第二种方式:
class woman;//先声明类
class man{
public:
    void func1(const woman& w);//定义出要调用的函数
    void func2(const woman& w);
};
class woman{
    friend void man::func1(const woman& w);//声明友元
    friend void man::func2(const woman& w);

private:
    int i=2;
    int j=2;
};
//实现友元函数
void man::func1(const woman& w) {
    cout<<__func__ <<","<<w.i<<","<<w.j<< endl;
}
void man::func2(const woman &w) {
    cout<<__func__ <<","<<w.i<<","<<w.j<< endl;
}
int main(){
    man m;
    woman w;
    m.func1(w);
    m.func2(w);
}