//
// Created by 36302 on 2023/4/23.
//
/*
 * 成员函数非必要不要返回对成员变量的引用或指针,降低了封装
 */
#include "test_base.h"
class base{
public:
    int & getI(){
        return i;
    }
private:
    int i;
};
int main(){
    base b1;
    int i=b1.getI();
    int j=base().getI();//变量引用被销毁访问了错误的空间
    cout<<i<<","<<j<<endl;
    return 0;
}