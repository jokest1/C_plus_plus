//
// Created by 36302 on 2023/4/26.
//
#include "test_base.h"
/*
 * auto的推导规则在T的推到规则上加入了initializer_list<T>可变参数模板类型
 * C11加入了{}初始化,这个初始化使用了可变参数模板类型,auto={}会得出这个类型
 */
int main(){
    int i=10;
    auto ii=i;
    auto iii={1,111};
    cout<<boost::typeindex::type_id_with_cvr<decltype(ii)>()<<endl;
    cout<<boost::typeindex::type_id_with_cvr<decltype(iii)>()<<endl;
    return 0;
}