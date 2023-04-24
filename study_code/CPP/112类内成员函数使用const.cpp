//
// Created by 36302 on 2023/4/21.
//
#include "test_base.h"
/*
 * const的语法表示常量的不该去修改的,如果某个成员函数不改变任何内容用const去修饰
 * const仅仅只能限制类内的成员变量的修改,无法限制对类指向空间的修改
 * 对于const成员和no-const的重载如果是重复的操作要用no-const去调用const
 */
class TestLength{
public:
    TestLength(char *pt) : pt(pt) {}
    char& operator[](std::size_t index)const{
        return pt[index];
    }
    char& operator[](std::size_t index){
        return const_cast<char&>(
                static_cast<const TestLength&>(*this)[index]
                );
        //在非const修饰的内部先转为const后调用const版本,之后再转回no-const版本
        //因为no-const本就是可变的转为const也符合语法所以转换合理
        //反之不合理
    }
    char* pt;
    mutable int count;//在const修饰的this中被mutable修饰的变量仍可以被修改内容
};
int main(){
    if(false){
        char ph[]="hello word!";
        ph[0]='j';//no-const 修改正确
        const char* cph=ph;
//        cph[0]='h';//const 修改错误
    }
    if (false){
        cout<<"---"<<endl;
        TestLength tl1({"hello word"});
        cout<<"---"<<endl;
        tl1[0]='j';//no-const
        cout<<"---"<<endl;
        const TestLength ctl({"hello word"});
        //在返回值的位置去掉const限制
        ctl[0]='j';//虽然const但是修改的并非类内空间所以被修改了
        cout<<"---"<<endl;
        cout<<ctl.pt<<endl;
    }
    return 0;
}