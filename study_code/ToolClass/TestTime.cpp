//
// Created by 36302 on 2023/4/21.
//
#include "TestTool.h"
class Sort{
public:
    void test(){
        int n=10;
        while (n)std::cin>>n;
    }
};


int main(){
    Sort st;
    std::cout<<"执行到此处"<<std::endl;
    Timer("test",st,&Sort::test);
    return 0;
}
