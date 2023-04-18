//
// Created by 36302 on 2023/4/18.
//
#include "test_base.h"
/*
 * string是字符容器，内部维护了一个动态的字符数组
 * 与普通字符数组相别:1.使用时候不必考虑分配释放2.动态管理内存3.提供了大量操作容器的接口
 * string是以1字节组织数据的所以string不止表示字符串,还可以用于管理一片存储数据的内存片段或用于缓冲区
 * 内部使用三个指针实现的 start指向内存片开始位置,end_of_strong指向字符串尾后地址,finish指向内存片尾后
 */
int main(){

//    构造函数
//  string(); 创建一个空的字符串
//  即使是空串也预先分配了15字节的空间
    string str1;
    cout<<"容量是:"<<str1.capacity()<<" 内容长度:"<<str1.length()<<endl;
//  string(const char *s);
//      将string对象初始化为s指向的字符串
    string str2("12345");
    cout<<"容量是:"<<str2.capacity()<<" 内容长度:"<<str2.length()<<endl;
//    string(const string &str);
//      拷贝构造函数
    string str3(str2);
    cout<<"容量是:"<<str3.capacity()<<" 内容长度:"<<str3.length()<<endl;
//    string(const char *s,size_t n);
//      将string初始化为字符串前n个字
    string str4("hello word",7);
    cout<<"str4:"<<str4<<endl;
    cout<<"容量是:"<<str4.capacity()<<" 内容长度:"<<str4.length()<<endl;
//    string(const string &str,size_t pos=0,size_t n=npos);
//      将string初始化为string类型的pos到npos的字符
    string str5(str4,0,4);
    cout<<"str5:"<<str5<<endl;
    cout<<"容量是:"<<str5.capacity()<<" 内容长度:"<<str5.length()<<endl;
//    string(size_t n,char c);
//      将string初始化为n个c字符
    string str6(7,'x');
    cout<<"str6:"<<str6<<endl;
    cout<<"容量是:"<<str6.capacity()<<" 内容长度:"<<str6.length()<<endl;
//    string(initializer_list<char> il)
//      列表构造,将string初始化为列表内字符
    string str7{'h','h','h','h','h','h','h'};
    cout<<"str7:"<<str7<<endl;
    cout<<"容量是:"<<str7.capacity()<<" 内容长度:"<<str7.length()<<endl;
//    特性操作
//    size()返回内存中实际使用的字节数/length()返回内存中字符串的长度
    string test("qwertyuiopasdfghjklzxcvbnm");
    cout<<"字符串的长度"<<test.length()<<endl;
    cout<<"内存中使用的空间:"<<test.size()<<endl;
//    capacity()返回实际分配的内存片长度
    cout<<"总共分配了:"<<test.capacity()<<"字节"<<endl;
//    clear()清空内存片内所有数据,empty()判断内存中置否有数据
//    resever(size_t size)将内存片至少分配size个字节
    test.reserve(26);//扩展后至少会是原来内存大小的二倍
    cout<<"重新分配空间后:"<<test.capacity()<<endl;
//    resize(size_t size,char c)//将空间分配size大小,扩展了的空间填写c,压缩了空间直接截断但不减少内存片大小
    test.resize(15,'x');
    cout<<"resize重新分配空间后:"<<test.capacity()<<endl;
    cout<<"字符串内容:"<<test<<endl;

//    字符操作
//    string重载了[]运算符可以通过下标随机访问,at与[]语义一样但是会检查下标
    for (int i = 0; i < 15; ++i) {
        cout<<"test["<<i<<"]:"<<test[i]<<",";
    }
    cout<<endl;
//    const char* c_str()const;//返回动态字符的首地址,目的是找到第一个字符串
    cout<<"c_str: "<<test.c_str()<<endl;
//    const char* data()const//找到内存片的首地址只关心01数据
    cout<<"data: "<<test.data()<<endl;

//    连接操作
//      重载了+=运算符拼接字符串
    string s1("hello");
    string s2(" word");
//    通过append拼接,重载了(const char *s)     //字符串常量拼接
//              ,(const string &str)        //string拼接
//              ,(const char *s,size_t n)   //字符串常量拼接前n个字符
//              ,(const string &str,size_t pos=0,size_t n=npos)//string拼接从pos到npos
//              ,(T begin,T end)            //将bengin到end拼接
//              ,(size_t n,char c)          //拼接n个c字符
//      类似于五个构造函数
    s1+=s2;
    cout<<s1<<endl;
    s2.append("xx");
    cout<<s2<<endl;
    s2.append(s1);
    cout<<s2<<endl;
    s2.append("yyyyyy",3);
    cout<<s2<<endl;
    s2.append(s1,0,1);
    cout<<s2<<endl;
    s2.append(s1.begin(),s1.end());
    cout<<s2<<endl;
    s2.append(3,'-');
    cout<<s2<<endl;
//    交换操作swap(string& str)//内容与str互换实际上只换了内部三个指针
    cout<<s1<<endl;
    cout<<s2<<endl;
    s2.swap(s1);
    cout<<"交换后:"<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

//    字符串截取操作 string substr(n,np)
    cout<<s1.substr(0,5)<<endl;

//    字符串比较操作
    cout<<(str1==str2)<<endl;
    cout<<str1.compare(str2)<<endl;//比较返回- 0 + 表示大等小

//    find串内查找函数
    cout<<(s1.find("w"))<<endl;
    return 0;
}