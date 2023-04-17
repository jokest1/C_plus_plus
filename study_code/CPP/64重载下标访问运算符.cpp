//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>

using namespace std;
/*
 * 如果类中有类似数组的数据类型需要提供像访问内置数组类型一样方便的[]运算符
 * 语法: 自定义类型名& operator[](int index);
 * 还要提供不可以修改数组元素的重载 const自定义类型名& operator[](int index)const;
 */
class friends{
private:
    string name;
    string f_name[3];
public:
    friends(const string &name, const string &one,const string &two,const string &three)
    : name(name) {
        f_name[0]=one;
        f_name[1]=two;
        f_name[2]=three;
    }
    friends() {name="1";
        f_name[0]="2";
        f_name[1]="3";
        f_name[2]="4";
    }
    string & operator[](int index){
        return f_name[index];
    }
    const string & operator[](int index)const{
        return f_name[index];
    }
};
int main(){
    friends f;
    f[0]="zhang";
    cout<<f[0]<< endl;
    cout<<f[1]<< endl;
    cout<<f[2]<< endl;
    return 0;
}