//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * class会默认提供copy构造,operator=,~class三种函数
 * 但是类内含有const,reference类型的类内数据无法使用默认提供的函数
 */

class Test{
public:
    void print(){
        cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
    }
private:
    int i=10;
    int j=10;
    int k=10;
};
class Test1{
public:
    void print(){
        cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
    }

    Test1(const int i, int &j, int k) : i(i), j(j), k(k) {}

private:
    const int i;
    int& j;
    int k=10;
};
int main(){
    if(false){
        /*
         * 验证了类内提供默认的copy和operator=
         */
        Test t1;
        Test t2(t1);
        Test t3;
        t3=t2;
        t1.print();
        t2.print();
        t3.print();
    }
    if (true){
        int i=10;
        Test1 t1(i,i,i);
        t1.print();
        Test1 t2(t1);
        t2.print();
//        t2=t1;因为类内含有const 和引用类型无法使用默认提供的operator=
    }
    return 0;
}