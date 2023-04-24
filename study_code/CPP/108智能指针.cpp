//
// Created by 36302 on 2023/4/21.
//
#include "test_base.h"
class name1;
class name{
public:
    weak_ptr<name1> m_n;
    name(){
        cout<<"调用了name构造函数\n";
    }
    virtual ~name() {
        cout<<"name析构函数被调用\n";
    }
};
class name1{
public:
    //weak_ptr的lock()方法,只能去知道内存是否还活着而不能去访问,活着的话转为share_ptr;
    weak_ptr<name> m_n;
    name1(){
        cout<<"调用了name1构造函数\n";
    }
    virtual ~name1() {
        cout<<"name1析构函数被调用\n";
    }
};
//shared_ptr<name> shna(new name);
int main(){
    if(false){
        //    只有new 没有delete只会调用构造函数而没有调用析构函数
        auto np=new name;
        //delete np;//使用delete会调用析构函数
//    使用智能指针中的unique_ptr在结束时候会调用析构函数
        unique_ptr<name> uina2(np);//这个构造不推荐因为np先被new出来
//    unique_ptr<name> uina2(nina);//会报错没有拷贝构造
//    unique_ptr<name> uina2=nina;//会报错没有重载=
        unique_ptr<name> uina(new name);//推荐使用这个构造
        unique_ptr<name> uina1= make_unique<name>();//C++14不足够兼容
    }

    if (false){
        //共享智能内部会记录共有多少个指针指向这个内存
        shared_ptr<name> shna1(new name);         //可以拷贝构造
        cout<<"有"<<shna1.use_count()<<"共享这片内存\n";
        shared_ptr<name> shna2(shna1);
        shared_ptr<name> shna3(shna1);
        cout<<"有"<<shna1.use_count()<<"共享这片内存\n";
        exit(-1);//exit退出,局部share_ptr并不会调用析构函数
    }
    if (true){
        shared_ptr<name> n1(new name);
        shared_ptr<name1> n2(new name1);
//        这种相互包含的情况最后并不会调用析构函数
        n1->m_n=n2;
        n2->m_n=n1;

    }
    return 0;
}