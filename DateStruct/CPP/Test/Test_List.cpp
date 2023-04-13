//
// Created by 36302 on 2023/3/27.
//
#include <list>
#include <string>
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::list<T>& v)
{
    //重写<<运算符
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
void test_create(){
    //    采用了列表初始化的方式 通过{}来进行直接初始化，每个元素之间用，分割
    std::list<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';
//    采用了迭代器初始化的方式，list(开始位置，结束位置)初始化新的list
    std::list<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
//    拷贝构造的方式将用list去初始化一个相同的list
    std::list<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';
//    采用了（数字，初始化的值）这样会初始化数字个初始化值的list
    std::list<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';
}

void test_get(){
    std::list<char> chars{'a','b','c','d'};
    std::cout<<chars.front()<<"\n";
//    front()获取第一个元素，back()获取最后一个元素
    std::cout<<chars.back()<<"\n";
    std::cout<<std::endl;
}
void test_capacity(){
    std::list<int> ints(10,10);
    ints.begin();//返回头迭代器
    ints.cbegin();//返回常量头迭代器
    ints.end();//返回尾部
    ints.cend();//返回常量尾部
    ints.rbegin();//最后一个元素迭代器
    ints.rend();//头前迭代器
    std::cout<<ints.empty()<<std::endl;
    std::cout<<ints.size()<<std::endl;
    std::cout<<ints.max_size()<<std::endl;

}
void test_mod(){
    std::list<int>ints;
    for (int i = 0; i < 10; ++i) {
        ints.push_back(i);
    }
    std::vector<int >clist;
    for (int i = 100; i >70 ; --i) {
        clist.push_back(i);
    }
    std::cout<<ints<<std::endl;
    auto b=ints.begin();
    ints.emplace(ints.begin(),int(10));
    std::cout<<ints<<std::endl;

}
int main()
{
    test_mod();
    return 0;
}