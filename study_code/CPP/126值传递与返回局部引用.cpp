//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 值传递一个类会根据类的具体大小来决定传递的速度
 * 而且会有多次的copy调用浪费大量空间不如使用const class&
 * 返回局部的引用直接报错
 */
class testReference{
private:
    int j;
    int i;
    string str;
public:
    testReference() {
        cout<<"调用了无参构造函数"<<endl;
    }
    testReference(const testReference& trf) {
        cout<<"调用了copy构造函数"<<endl;
    }
    testReference& operator=(const testReference& trf){
        cout<<"调用operator="<<endl;
    }
    virtual ~testReference() {
        cout<<"调用了析构函数"<<endl;
    }
};
void test(const testReference& trf){

}

testReference& test2(){
    //返回局部的引用直接报错
//    return testReference();
}
int main(){
    testReference trf;
    test(trf);
    return 0;
}