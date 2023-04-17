//
// Created by 36302 on 2023/4/16.
//
#include <iostream>
#include <string>
/*
 * 重载关系运算符要与原语义一致所以传递的应该是相同的自定义类型返回值为bool
 * ==和!=可以通过相互调用后取反实现
 * <和>也可同样如此
 */
using namespace std;
//创建自定义类型
class student{
private:
    string name;
    int chinese;
    int english;
public:
    student(const string &name, int chinese, int english) : name(name), chinese(chinese), english(english) {}
//    重载关系运算符号==和!=
    bool operator==(const student& s)const{
        if (this->chinese==s.chinese&& this->english== s.english)
            return true;
        return false;
    }
//    !=可以通过调用==操作符来实现
    bool operator!=(const student& s)const{
        return !operator==(s);
    }
//    重载<和>
    bool operator<(const student& s)const{
        if((this->english+ this->chinese)<(s.chinese+s.english))
            return true;
        return false;
    }
    bool operator>(const student& s)const{
//        大于通过对<的取反进行实现
        return !(this->operator<(s));
    }
};

int main(){
    student one("张三",20,30);
    student two("李四",20,30);
    student three("王五",30,40);
    if (one==two)
        cout<<"两人成绩相同"<<endl;
    if(three!=two)
        cout<<"两人成绩不相同"<<endl;
    if(two<three)
        cout<<"王五成绩更好"<<endl;
    if (three>one)
        cout<<"王五成绩更好"<<endl;

    return 0;
}