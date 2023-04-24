//
// Created by 36302 on 2023/4/22.
//
#include "test_base.h"
/*
 * 1.考虑会进行的错误调用
 * 2.将大类中的成员划分出相关的小类
 * 3.在小的类型里进行限定值
 * 4.自动定义class要向type看起一致
 * 5.接口要求用户去做什么将会有不确定行为
 */
class Date{
private:
    struct Day{
    private:
        int day;
    public:
        Day(int day) : day(day) {}
    };
    struct Month{
    private:
        int month;
    public:
        Month(int month) : month(month) {}
    };
    struct Year{
    private:
        int year;
    public:
        Year(int year) : year(year) {}
    };
    Day day;
    Month month;
    Year year;
public:
    Date(const Day &day, const Month &month, const Year &year)
    : day(day), month(month), year(year) {}
};