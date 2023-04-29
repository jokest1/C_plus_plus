cmake_minimum_required(VERSION 3.22)
project(study_code)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
#添加头文件搜索路径
include_directories(C:/boost_1_82_0)

#添加库文件搜索路径
link_directories(C:/boost_1_82_0/libs)


#Chapter0 测试代码
add_executable(study_code  CPP/154探索constexpr.cpp)

#数据结构部分
#add_executable(study_code DateStruct/LineList.h DateStruct/Test.cpp DateStruct/abstractLine.h DateStruct/Array.h DateStruct/Tree.h DateStruct/DynamicArray.h DateStruct/LinkList.h DateStruct/DoubleLinkList.h DateStruct/CircleLink.h DateStruct/stack.h DateStruct/queue.h)
