//
// Created by 36302 on 2023/4/27.
//
#include "test_base.h"
/*
 * auto虽然会根据初始化时候的类型决定类型但是会降低代码可读性
 * 在知道大概类型不需要具体类型时候使用
 * auto会提高代码的兼容性
 * C++存在隐式的代理类如vector有特化的bool版本,使用auto后出现了std::_Bit_reference,而不是bool类
 */

int main(){
    int i=10;
    cout<<boost::typeindex::type_id_with_cvr<decltype(i)>().pretty_name()<<endl;
    vector<bool> vb(5,"true");
    cout<<boost::typeindex::type_id_with_cvr<decltype(vb[3])>().pretty_name()<<endl;
    return 0;
}