//
// Created by 36302 on 2023/4/26.
//
#include "test_base.h"
//模板T的推导规则:
//      **首先忽略掉传递前变量的一层引用或者指针修饰
//      **const也会传递
//      1.传递指针或者应用但是不是万能引用
//            **
//            2.推导出变量的基本类型后就是T的类型
//            3.形参的类型是会加上形参的修饰符
//      2.传递万能引用
//            **
//            2.如果是左值:推导出变量的基本类型的引用就是T的类型和形参类型
//            3.如果是右值:推导出右值的基本类型是T类型,实参类型为右值引用
//      3.传递的既非引用也非指针
//            1.直接当作值传递,因为值传递为副本所以const也会消失,右值推断出类型后值传递
template<typename T>
void printType1(T& t1){
    cout<<"T的类型:"<<boost::typeindex::type_id_with_cvr<T>().pretty_name()<<endl;
    cout<<"T&的类型:"<<boost::typeindex::type_id_with_cvr<decltype(t1)>().pretty_name()<<endl;
}
template<typename T>
void printType2(T&& t1){
    cout<<"T的类型:"<<boost::typeindex::type_id_with_cvr<T>().pretty_name()<<endl;
    cout<<"T&&的类型:"<<boost::typeindex::type_id_with_cvr<decltype(t1)>().pretty_name()<<endl;
}
template<typename T>
void printType3(T t1){
    cout<<"T的类型:"<<boost::typeindex::type_id_with_cvr<T>().pretty_name()<<endl;
}

int main(){
    //调用boost库的typeindex中的type_id_with_cvr<T>()模板类
    //命名规则typeid伴随 常量c指针v引用r
//    cout<< boost::typeindex::type_id_with_cvr<int>().pretty_name()<<endl;
    const int i=10;
    const int& ri=i;
    printType3(i);
    printType3(ri);
    printType3(11);
    return 0;
}