//
// Created by 36302 on 2023/4/21.
//
/*
 * c11提供了线程
 * 为了统一操作跨平台
 */

#include "test_base.h"
void func(int n,string no){
    cout<<"线程的id: "<<this_thread::get_id()<<endl;//可以取出线程的id
    if(false){
        for (int i = 0; i < 10; ++i) {
            cout<<"第"<<n<<","<<no<<endl;
            Sleep(100);
        }
    }
}
/*
 * thread的构造函数可以是成员函数,静态函数,lamda表达式
 */
int main(){
    thread t1(func,2,"123");
    thread t2([](){
        cout<<"线程的id: "<<this_thread::get_id()<<endl;//可以取出线程的id
    });
    t1.detach();//分离子线程会自动回收资源
    t2.detach();//分离子线程会自动回收资源
    Sleep(3000);
    //t1.join();
    //t2.join();//主线程回收子线程
    return 0;
}