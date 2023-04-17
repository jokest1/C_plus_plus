//
// Created by 36302 on 2023/4/17.
//
#include <iostream>

using namespace std;

int main(){
    int i=10;
    int* pi=&i;
    int& ri=i;
    cout<< typeid(i).name()<<endl;
    cout<< typeid(int ).name()<<endl;
    cout<< typeid(pi).name()<<endl;
    cout<< typeid(int* ).name()<<endl;
    cout<< typeid(ri).name()<<endl;
    cout<< typeid(int& ).name()<<endl;
//    typeid返回type_info类型的引用,type_info的构造是peivate但是内部重载了==和!=
    if (typeid(int)== typeid(i))
        cout<<"ok,int"<<endl;
    return 0;
}