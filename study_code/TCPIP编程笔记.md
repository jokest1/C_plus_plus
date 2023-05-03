- [第一部分](#第一部分)
  - [第一章 理解`网络编程`和`套接字`](#第一章-理解网络编程和套接字)
    - [接收端](#接收端)
    - [发送端](#发送端)
  - [第二章 套接字类型与协议设置](#第二章-套接字类型与协议设置)
  - [第三章 地址簇和数据序列](#第三章-地址簇和数据序列)
    - [地址簇的设计与使用](#地址簇的设计与使用)
    - [字节序列(大小端存储)](#字节序列大小端存储)
  - [第四章 基于TCP的服务器端/客户端](#第四章-基于tcp的服务器端客户端)
    - [理解TCP和UDP](#理解tcp和udp)
    - [实现基于TCP的C/S](#实现基于tcp的cs)
  - [第五章 深入了解TCP](#第五章-深入了解tcp)
    - [无数据边界](#无数据边界)
    - [TCP的原理](#tcp的原理)
    - [TCP的工作原理](#tcp的工作原理)
  - [第六章 基于UDP的C/S](#第六章-基于udp的cs)
    - [UDO工作原理](#udo工作原理)
    - [实现基于UDP的C/S](#实现基于udp的cs)
  - [第七章 对于套接字的断开操作](#第七章-对于套接字的断开操作)
  - [第八章 DNS域名解析服务](#第八章-dns域名解析服务)
  - [第九章 套接字的多种可选项](#第九章-套接字的多种可选项)
    - [套接字可选项与IO缓冲大小](#套接字可选项与io缓冲大小)
    - [SO\_REUSEADDR可选项](#so_reuseaddr可选项)
    - [Nagle 算法](#nagle-算法)
  - [第十章 多进程服务器](#第十章-多进程服务器)
    - [进程的概念](#进程的概念)
    - [理解进程](#理解进程)
    - [创建进程](#创建进程)
    - [创建僵尸进程](#创建僵尸进程)
    - [销毁僵尸进程](#销毁僵尸进程)
    - [销毁僵尸进程但不阻塞](#销毁僵尸进程但不阻塞)
    - [信号处理](#信号处理)
    - [signal函数与信号](#signal函数与信号)
    - [使用通用的信号注册](#使用通用的信号注册)
    - [在程序中利用信号处理技术](#在程序中利用信号处理技术)
    - [基于多任务的并发服务器](#基于多任务的并发服务器)
    - [分割TCP的IO程序](#分割tcp的io程序)
  - [第十一章 进程间通信](#第十一章-进程间通信)
    - [对进程间通信的基本理解](#对进程间通信的基本理解)
    - [通过管道实现进程间通信](#通过管道实现进程间通信)
    - [通过管道进行双向通信](#通过管道进行双向通信)
    - [运用进程间通信](#运用进程间通信)
# 第一部分
主要学习网络编程的基础知识 **windows和linux下必备的基础知识 `采用的C语言编写`** 指出了windows和Linux的网络编程的差异部分后续内容将围绕单一系统进行

## 第一章 理解`网络编程`和`套接字`

在编程中文件操作和输入输出都很相似,实际上网络编程也和文件操作相类似

`网络编程`就是编写程序使得两台计算机交换数据,这就是网络编程的全部内容.物理上已经有网络将计算机相连结了,只需要关心如何编写软件,而操作系统提供了`套接字`用于网络传输用的软件部分

`套接字分为了两类`TCP套接字比喻成电话需要有拨打方和接收方且先建立联通后才交换数据.
### 接收端
TCP套接字接受端建立过程`Linux下`:
1. 通过socket函数创建接收方
```cpp
#include<sys/socket.h>
int socket(int domin,int type,int protocol);
    // ->成功时返回文件描述符,失败返回-1
```
1. 通过bind函数将信息与套接字关联
```cpp
#include<sys/socket.h>
int bind(int sockfd,struct sockaddr* myarr,socklen_t addrlen);
    // ->失败返回-1,成功返回0
```
1. 通过listen函数监听申请
```cpp
#include<sys/socket.h>
int listen(int sockfd,int backlog);
    // ->成功返回0,失败返回-1
```
1. 通过accept函数建立连接
```cpp
#include<sys/socket.h>
int accept(int sockfd,struct sockaddr* addr,socklen_t* addrlen);
    // ->返回-1为失败,成功返回描述符
```
### 发送端
TCP套接字发送端建立过程`Linux下`:
1. 通过socket函数创建接收方
```cpp
#include<sys/socket.h>
int socket(int domin,int type,int protocol);
    // ->成功时返回文件描述符,失败返回-1
```
1. 通过connect函数请求连接
```cpp
#include<sys/socket.h>
int connect(int sockfd,struct sockaddr* serv_addr,socklen_t addrlen);
    // ->成功返回0,失败返回-1
```
`windows`平台的socket比`Linux`增加了初始化winsock
```cpp
#includ<winsock2.h>
//主体框架
int main(){
    WSADATA wsaData;
    ....
    if(WSAStartup(MAKEWORD(2,2),&wsaDate)){
        return -1;
    }
    // ...初始化结束正常socket
    return 0;
}
```
## 第二章 套接字类型与协议设置
协议就是为了完成数据交换而定好的约定,就像两个人交流使用同样的语言和设备一样
`创建套接字`函数socket上面已经写出了定义,介绍一下传递的参数:
1. `domin`是套接字中使用掉协议簇信息主要有:
   1. `ipv4`            PF_INET
   2. `ipv6`            PF_INET6
   3. `UNIX协议`        PF_LOCAL
   4. `底层套接字协议`   PF_PACKET
   5. `IPX协议`         PF_IPX
2. `tepy`是套接字类型,也就是数据传输类型:
   1. 面向连接的传输方式,需要传送与接受一一对应:
      1. 传输过程中数据不会丢失
      2. 按顺序传送
      3. 传输的数据不存在数据边界
   2. 面向消息的传输方式,单一的向目标发送:
      1. 强调快速而非稳定
      2. 传输的数据可能丢失
      3. 每次传输都有大小限制
      4. 传输的有数据边界`(传送和接受次数对应)` 
   3. 协议的最终选择取决于`protocol`同一个协议簇中又有多个传送方案
## 第三章 地址簇和数据序列
### 地址簇的设计与使用
分配端口号和IP地址给套接字

`IP`是`网络协议`的简称,是为了收发网络数据而分配给计算机的值,端口号不是赋予计算机的值而是为了区分不同套接字而创建的序号

**网络地址:** 为了使计算机连接到网络并且收发数据必须向其分配IP地址,共有两类IP地址:`IPV4(4字节)`和`IPV6(16字节)`.后者是因为IPV4即将耗尽而推出

**IPV4:** 资格字节的`IP地址`分为了两部分:网络地址和主机地址，网络地址是为了区分网络而设置的一部分`IP地址`，假设这个网络内部又构建了局域网则交由主机地址进行区分。

**用于区分套接字的端口号:** `IP地址`用于区分了计算机,只要有IP地址就能够向计算机发送消息.然而仅凭这些并不能最终将数据传送给程序,如何区分同时运行在计算机上的程序呢?通过端口号将套接字编号来进行区分.套接字共有16位`0-1023`使系统预留地址不能由用户使用,`同一个协议下端口号不允许重复`

**`地址信息的表示:`** 应用程序中的IP和端口号以结构体形式给出了定义
```cpp
struct sockarr_in{
    sa_family_t         sin_family; //地址簇
    unit16_t            sin_port;   //16位端口号
    struct in_addr      sin_addr;   //32位IP地址
    char                sin_zero[8];//占位符
}
struct in_addr{
    In_addr_t           s_arr;      //32位IPV4地址
}
//所有以_t结尾的变量定义全部都是POSIX标准
```
`sin_family`使用三种参数:PF_INET    ,PF_INET6    ,PF_LOCAL 

`sin_port`使用16位表示端口号

`in_addr` 是一个结构体用于存储32位`IP地址`

`sin_zero`是为了向结构体sockaddr`对齐内存`而占位使用
```cpp
struct sockarr{
    sa_family_t         sin_family; //地址簇
    char                sa_data[14];//地址信息
}
//因为sa_data数组并不好输入地址信息,通过将这个内存地址拆分后
//在不同的位置进行不同的初始化同时使用占位符进行填充内存对齐
```
### 字节序列(大小端存储)
`网络字节序和地址变化`:计算机内数据有两种存储方式:大端存储和小端存储,因为这种差异网络传输规定`统一使用大端存储`,故设计了字节序转换函数:`h`代表了本地,`n`代表了了网络,`l`代表四字节32位,`s`代表二字节16位,通过`to`连接形成了四个转换函数:
1. htons()      `16位本地转网络字节序`
2. ntohs()      `16位网络转本地字节序`
3. htonl()      `32位本地转网络字节序`
4. ntohl()      `32位网络转本地字节序`

`网络地址初始化分配:`习惯性使用点分十进制法,故需要将`"192.168.0.1"`转为32位二进制序列,通过函数`inet_addr(const char*)`和`inet_atoi(const char*,struct in_addr)`

`INADDR_ANY`代表本机IP地址

**`上述六个函数是在Linux系统下的而Windows系统下并不包含第六个函数`**
## 第四章 基于TCP的服务器端/客户端
### 理解TCP和UDP
根据传输数据的方式不同，传输协议分为了TCP套接字和UDP套接字，TCP面向连接又称为`基于流传输`

TCP/IP协议栈传输数据是一个很复杂的问题,是不可能靠一个协议完成的,将这个复杂问题进行分割,分为四层去处理:用户层->TCP/UDP层->IP层->数据链路层

数据链路层:是物理连接领域标准化的结果也是数据交换的基础,将网络按区域大小分为了:广域网,城域网,局域网

IP层:物理连接好了之后传输数据还要考虑传输的路径,这就是IP层`面向消息的不可靠传输`即使数据丢失IP都不处理

TCP/UDP层:IP解决了传输路径问题,而对数据完整有效和数据序列并不负责,为了保证还原数据检测错误,`TCP/UDP层`就是负责解决数据传输与还原的协议

应用层:上述三层是套接字自动处理的对于用户是隐藏操作,只需要使用套接字传输数据即可

### 实现基于TCP的C/S
TCP服务器有着默认执行顺序:
1. `socket(IP协议,消息传输方式,具体方式)`创建套接字,初始化客户端的结构体信息,如:客户端的IP/用于连接的端口地址/使用的协议
2. 使用`bind(套接字,结构体信息指针,结构体大小)`将套接字和客户端的结构体信息绑定在一起
3. `listen(套接字,等待序列长度)`进入监听状态,只有进入了这个状态客户端才能通过`connect()`进行连接 *此时的客户端套接字并不是用于数据交流的而是只负责监听*
4. `accept(服务器套接字,客户端结构体地址,结构体大小)`建立连接并且在内部会通过这个结构体和结构体大小自动创建客户端交流的套接字并作为返回值返回
5. `read()/write()`建立好了数据连接后就可以开始传输交换数据了
6. `close(套接字)`数据交换结束后就将连接断开了,要先断开客户端才能关闭服务端
```cpp
// 对以上流程进行代码编写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//头文件的包含
int main(int argc,char* argv[]){
    int sever_socket,client_socket;//服务器客户端套接字
    struct sockaddr_in sever_addr;//定义服务器端地址
    struct sockaddr_in client_addr;//定义客户器端地址
    socklen_t client_addr_len;//定义客户器端地址长度
    memset(&sever_socket,0, sizeof(sever_socket));

    //获得一个独立套接字
    sever_socket= socket(PF_INET,SOCK_STREAM,0);
    //初始化服务器端结构体信息
    sever_addr.sin_family=PF_INET;//设置为ipv4
    sever_addr.sin_port= htons(atoi(argv[1]));//初始化端口号char*->int->网络字节序
    sever_addr.sin_addr.s_addr= htonl(INADDR_ANY);//初始化ip地址:INADDR_ANY自己地址

    //将结构体与套接字进行绑定
    bind(sever_socket,(struct sockaddr*)&sever_addr, sizeof(sever_addr));
    
    //使套接字进入监听状态
    puts("进入监听");
    listen(sever_socket,5);
    char buffer[1024]={0};
    int strlen=0;
    
    for (int i = 0; i < 5; ++i) {
        //监听开始会阻塞进程,一旦运行到accept就是有连接
        puts("有连接申请");
        client_socket=accept(sever_socket,(struct sockaddr*)&client_addr,&client_addr_len);
        printf("第%d次监听",i+1);
        //开始交换数据一读一写
        strlen= read(client_socket,buffer,1023);
        buffer[strlen]=0;
        puts(buffer);
        write(client_socket,buffer,strlen);
    }
    
    //结束连接
    puts("5次连接结束了!");
    close(client_socket);
    close(sever_socket);
    return 0;
}
```
TCP客户器有着默认执行顺序:
1. `socket(IP协议,消息传输方式,具体方式)`创建套接字,初始化客户端的结构体信息
2. `connect(套接字,地址信息,地址信息长度)`向服务器发起连接请求
3. `read()/write()`建立好了数据连接后就可以开始传输交换数据了
4. `close(套接字)`数据交换结束后就将连接断开了,断开连接
```cpp
// 对以上流程进行代码编写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//头文件的包含
int main(int argc,char* argv[]){
    int sock;
    struct sockaddr_in socket_addr;
    memset(&socket_addr,0, sizeof(socket_addr));

    //获得一个独立套接字
    sock= socket(PF_INET,SOCK_STREAM,0);
    char buffer[30]={"hello word!!"};
    //初始化套接字信息
    socket_addr.sin_family=PF_INET;
    socket_addr.sin_port= htons(atoi(argv[2]));
    socket_addr.sin_addr.s_addr= inet_addr(argv[1]);
    //向客户端发起连接
    connect(sock,(struct sockaddr*)&socket_addr,sizeof (socket_addr));
    //读写数据
    write(sock,buffer, strlen(buffer));
    read(sock,buffer, sizeof(buffer)-1);
    puts(buffer);
    //关闭连接
    close(sock);
    return 0;
}
```
## 第五章 深入了解TCP
### 无数据边界
TCP是没有边界的传输方式,所以读写可以不对等存在,在上一章中一次read对应着一次write是需要进行改进的地方,可以等缓冲区buffer满了之后一次性进行读操作,缓冲区的存在可以减少对读的操作次数
### TCP的原理
`TCP`无数据边界,既可以分批次接受发送也可以一次性读取发送,实现这种方式的方法是在`TCP层`设置独立的输入输出缓冲区用来缓存而非立即发送,缓冲区特性有:
1. I/O缓冲在每个`TCP套接字`中单独存在
2. I/O缓冲在创建套接字时候自动生成
3. 即使关闭套接字也会继续传`输出缓冲区`中遗留的数据
4. 关闭套接字丢失`输入缓冲区`中的数据

**`在传送过程中并不会发生缓冲区不对等大小的数据丢失,因为每次传送数据都会将自己的缓冲区剩余大小作为附带信息发送给对方`**

### TCP的工作原理
与对方套接字进行连接分为了以下三部:

1. 与对方套接字建立连接
2. 与对方进行数据交换
3. 与对方套接字断开连接
实际通信中也会存在三次对话过程被称为`三次握手`:客户端向服务端发送连接申请->服务器端接受申请并返回->客户端向服务器建立连接;`套接字是全双工的工作方式`在每次消息传送中有`SEQ`和`ACK`来表示传送的数据包序列

与对方断开连接分为了四部:

1. 客户端发出断开申请
2. 服务器端会送接受申请
3. 服务器端发送断开申请
4. 客户端断开申请

这个断开连接的过程称之为`四次握手`

## 第六章 基于UDP的C/S
`TCP/UDP`同属于传输层,只是两个方式的传送数据特点不同,上边已经介绍了`TCP`现在了解`UDP`,工作原理像寄信一样写上对方的地址并将内容装入信封,对方是否收到信封是否破损寄件方都无从得知,这是一种面向不可靠连接的传输方式

确实只考虑可靠性`TCP`远强于`UDP`但是`UDP`结构上更加简单,不会发送`ACK应答`和`SEQ序列号`,因此`UDP`在性能上高于`TCP`
### UDO工作原理
IP负责了计算机到计算机之间的传输,而UDP又不提供可靠的消息传输控制,所以UDP唯一的功能就是`区分消息具体传送到的端口号`
### 实现基于UDP的C/S
在`UDP`中没有连接存在因此只需要一个套接字来进行数据交流就好了,套接字是一一对应的,发送和接受都是统一因此不做区分也不需要listen和accept

基于UDP的I/O函数:
```cpp
ssize_t sendto(int sock,void* buffer,size_t nbytes,int flag,struct sockaddr* to,socklen_t addrlen);
//  ->返回送出的长度,失败-1
ssize_t recvfrom(int sock,void* buffer,size_t buffersize,int flag,struct sockaddr* from,socklen_t addrlen);
//  ->返回读取的长度,失败-1
```
基于UDP的服务器端实现:
```cpp
// 对以上流程进行代码编写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//头文件的包含
int main(int argc,char* argv[]){
    int sock;//创建套接字
    struct sockaddr_in sever_addr;//服务器自身地址信息
    struct sockaddr_in client_addr;//服务器自身地址信息
    socklen_t sockaddr_len= sizeof(sever_addr);//地址长度
    memset(&sever_addr,0,sizeof (sockaddr_in));

    //初始化为UDP协议
    sock= socket(PF_INET,SOCK_DGRAM,0);
    sever_addr.sin_family=PF_INET;//设置为ipv4
    sever_addr.sin_addr.s_addr= htonl(INADDR_ANY);//设置本机ip
    sever_addr.sin_port= htons(atoi(argv[1]));//设置好端口号
    //绑定套接字和地址信息
    bind(sock,(struct sockaddr*)&sever_addr,sockaddr_len);

    char buffer[1024];
    memset(buffer,0,1024);
    while (1){
//        fputs("请输入:",stdout);
        int strlen=0;
        //从绑定了端口的套接字读取信息,并且保存发送方的地址
        strlen=recvfrom(sock,buffer,1024,0,(struct sockaddr*)&client_addr,&sockaddr_len);
        //根据套接字像刚刚消息发送方回传数据
        sendto(sock,buffer,strlen,0,(struct sockaddr*)&client_addr,sockaddr_len);
    }
    return 0;
}
```
基于UDP的客户端实现:
```cpp
// 对以上流程进行代码编写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//头文件的包含
int main(int argc,char* argv[]){
    int sock;//用于交流的套接字
    struct sockaddr_in sever_addr,client_sever;//保存收件人地址
    memset(&sever_addr,0,sizeof (sever_addr));
    socklen_t sever_len= sizeof(client_sever);
    //创建套接字
    sock= socket(PF_INET,SOCK_DGRAM,0);
    //初始化收件人信息
    sever_addr.sin_family=PF_INET;
    sever_addr.sin_addr.s_addr= inet_addr(argv[1]);
    sever_addr.sin_port= htons(atoi(argv[2]));
    char buffer[1024]={0};
    int buflen=0;
    while (1){
        puts("q/Q退出");
        fgets(buffer,1024,stdin);
        if (!strcmp(buffer,"q\n"))
        {
            break;
        }
        //将数据发送出去
        sendto(sock,buffer, strlen(buffer),0,(struct sockaddr*)&sever_addr,sever_len);
        //接受数据
        buflen=recvfrom(sock,buffer,1024,0,(struct sockaddr*)&client_sever,&sever_len);
        buffer[buflen]=0;
        puts(buffer);
    }
    //断开连接
    close(sock);
    return 0;
}
```
**`如果第一sendto发现套接字没有分配地址,将会自动分配随机的地址信息,直到close后才会释放`** **如果要一直向某个服务器发送UDP数据可以使用`connect()`绑定后使用write和read进行数据交换**

## 第七章 对于套接字的断开操作
只有`TCP`是套接字有连接过程的,这个连接过程的建立很简单,但是断开这个连接的时机是很重要的,断开连接会发生意想不到的情况,如`close()函数`是将连接直接断开,输出区会继续输送而输入区会消失,这种会丢失数据因此`半关闭`诞生了,将读写分为两部分,可以断开读或者写其中一个
```cpp
int shutdown(int sock,int howto);
    //->返回0表示成功,返回-1失败
```
howto有三种:`SHUT_RD`,`SHUT_WR`,`SHUT_RDWR`

分析半关闭的设计需求:传输文件服务器只需要一直传输就好了,而客户端并不知道数据何时传递完毕,客户端无法一直读取又或者等待一段时间,这时候需要一个表示传输结束的`EOF`,这个不能是某个内容信息,而是应该特殊设计的标志.半关闭应运而生半关闭后传送出一个`EOF`标志断开连接.

## 第八章 DNS域名解析服务
域名是对一个ip地址的文字化,想要记录一个ip地址是很困难的,而将IP地址域名化则很容易记录

DNS服务器是通过记录域名和为IP地址的对应关系来寻找某个域名对应的IP地址的

利用域名获取IP地址
```cpp
struct hostent* gethostbyname(char char* hostname);
    // ->返回的是一个结构体的指针指向域名相关信息的结构体
struct hostent{
    char* h_name;       //官方域名
    char** h_allases;   //代表同一IP地址的其他域名
    int h_addrtype;     //保存IP地址的类型
    int h_length;       //保存IP地址的长度
    char** h_addr_list; //保存IP地址和指向同一个位置的其他IP地址
}
```
利用IP获得域名
```cpp
struct hostent* gethostbyaddr(const char* addr,socklen_t len,int family);
    // ->返回的是一个结构体的指针
```

## 第九章 套接字的多种可选项
### 套接字可选项与IO缓冲大小
我们进行套接字编程只关注了数据通信,而忽略了套接字具有不同特性.但是,理解这些特性根据需要更改也很重要

**套接字可选项是分层的:** `IPPROTO_IP`是`IP协议相关`,`IPPROTO_TCP`是`TCP协议相关`,`SOL_SOCKET`是`套接字通用可选项`

套接字修改可选项的读取
```cpp
int getsockopt(int sock,int level, int optname,void* optval,socklent_t *optlen);
/*
成功返回0,失败返回-1
sock:用于查看的选项的套接字
level:要查看的选项位于什么层
optname:查看的可选项名字
optval:保存查看结果的缓冲地址值
optlen:向第四个参数传递的缓冲大小,调用结束后保存可选信息内存的实际字节数
*/
```
套接字修改可选项的修改
```cpp
int socksetopt(int sock,int level,int optname,const void*optval,socklen_t optlen);
/*
成功返回0,失败返回-1
sock:用于修改的选项的套接字
level:要修改的选项位于什么层
optname:修改的可选项名字
optval:保存更改结果的缓冲地址
optlen:向第四个参数传递缓冲大小
*/
```
创建套接字会默认生成`io缓冲区`,`SO_RCVBUF`是输入缓冲区`可选项,SO_SNDBUF`书输出缓冲区可选项
```cpp
int main(){
    int sock;
    sock= socket(PF_INET,SOCK_STREAM,0);
    long long temp;
    socklen_t size=sizeof(temp);
    int len= getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(void*)&temp,&size);
    printf("输入缓冲区的大小%d\n",temp);
    len= getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void*)&temp,&size);
    printf("输出缓冲区的大小%d\n",temp);
    return 0;
}

输出结果:
输入缓冲区的大小87380
输出缓冲区的大小16384
```
对缓冲大小进行修改
```cpp
int main(){
    int sock;
    sock= socket(PF_INET,SOCK_STREAM,0);
    long temp=4080;
    socklen_t size=sizeof(temp);
    int len= setsockopt(sock,SOL_SOCKET,SO_RCVBUF,(void*)&temp,size);
    printf("输入缓冲区的大小%d\n",temp);
    len= setsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void*)&temp,size);
    printf("输出缓冲区的大小%d\n",temp);
    return 0;
}

输出结果:
输入缓冲区的大小4080
输出缓冲区的大小4080
```

### SO_REUSEADDR可选项

如果在服务器和客户端交换数据期间服务器强制停止工作,又立刻重启服务器会发生地址分配错误,这时候等待三分钟左右后就可以正常重启了.

主动关闭方在收到被动关闭方的FIN包后并返回ACK后，会进入TIME_WAIT状态，TIME_WAIT状态又称2MSL状态，每个TCP连接都必须有一个最大报文段生存时间MSL，在网络传输中超过这个时间的报文段将被丢弃。当TCP连接发起一个主动关闭，并发出最后一个ACK时，必须在TIME_WAIT状态停留两倍MSL时间，在2MSL等待期间，定义这个连接的插口(客户端IP地址和端口号，服务器IP地址和端口号的四元组)将不能再被使用

基于相同插口建立一个新的TCP连接，这个新的连接称为前一个连接的化身。老的报文很有可能由于某些原因迟到了，那么新的TCP连接很有可能会将这个迟到的报文认为是新的连接的报文，而导致数据错乱.为了防止这种情况的发生TCP连接必须让TIME_WAIT状态持续2MSL，在此期间将不能基于这个插口建立新的化身

如果主动关闭方最终的ACK丢失，那么服务器将会重新发送那个FIN,以允许主动关闭方重新发送那个ACK。要是主动关闭方不维护2MSL状态，那么主动关闭将会不得不响应一个RST报文段，而服务器将会把它解释为一个错误，导致TCP连接没有办法完成全双工的关闭，而进入半关闭状态。

### Nagle 算法
**`为了防止因为数据包过度而发生网络过载,Nagle算法诞生了`**,应用于TCP层,如果确认套接字连同稳定将会一次性发送大量数据,`且只有接收到前一数据的 ACK 消息， Nagle 算法才发送下一数据。`

## 第十章 多进程服务器
### 进程的概念
如果每一次服务1秒那么最后一个人的等待时间将会非常的长，应该牺牲平均服务时间减少每个人的平均等待时间，这就是并发服务器的设计思路，并发服务器的实现方法：
1. 多进程服务器：通过创建多个进程进行服务
2. 多路复用服务器：通过捆绑并统一IO对象进行服务
3. 多线程服务器：通过生成与客户端等量的线程进行服务

### 理解进程
`占用内存空间并且正在运行的程序叫做进程`，而如果只是从网络将程序下载到硬盘并不叫进程而是一个程序。加入同时使用音乐播放器和图书阅读工具就会产生多个进程，从操作系统来看进程是程序流的基本单位，程序是并行运行的

`进程的ID`无论怎么创建进程,所有进程都会被操作系统分配统一的ID这个值是大于2的整数,通过Linux的ps命令查看当前运行的进程
```Linux
[root@LiSir01 ~]# ps aux
USER        PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root          1  0.5  0.3 128276  6996 ?        Ss   09:22   0:02 /usr/lib/systemd/systemd --switched-
root          2  0.0  0.0      0     0 ?        S    09:22   0:00 [kthreadd]
root          3  0.0  0.0      0     0 ?        S    09:22   0:00 [kworker/0:0]
root          4  0.0  0.0      0     0 ?        S<   09:22   0:00 [kworker/0:0H]
root          5  0.0  0.0      0     0 ?        S    09:22   0:00 [kworker/u256:0]
root          6  0.0  0.0      0     0 ?        S    09:22   0:00 [ksoftirqd/0]
root          7  0.0  0.0      0     0 ?        S    09:22   0:00 [migration/0]
root          8  0.0  0.0      0     0 ?        S    09:22   0:00 [rcu_bh]
root          9  0.0  0.0      0     0 ?        R    09:22   0:00 [rcu_sched]
root         10  0.0  0.0      0     0 ?        S<   09:22   0:00 [lru-add-drain]
root         11  0.0  0.0      0     0 ?        S    09:22   0:00 [watchdog/0]

```

### 创建进程
创建进程的方式有很多种,首先介绍一个使用`fork()`函数进行进程创建
```cpp
#include<unistd.h>
pid_t fork(void);
//->成功返回值是子进程的PID,失败返回-1
```
`fork()`函数创建调用的进程的副本,另外父子进程都会指向创建之后的语句,之后的程序要根据`fork()`返回值进行区分了
    - 父进程:`fork()`返回的是子进程的ID
    - 子进程:`fork()`返回的是0
**调用fork()时候会先创建进程返回值是在创建完成之后根据不同进程进行返回的**
```cpp
int i=10;//全局
int main(){
    int j=11;
    i+=5;
    ++j;
    int p_id;
    p_id=fork();
    if (p_id==0){
        i+=5;
        ++j;
    }else{
        i-=5;
        ++j;
    }
    if (p_id==0){
        printf("我是子进程%d,i=%d,j=%d\n",p_id,i,j);
    }else{
        printf("我是父进程%d,i=%d,j=%d\n",p_id,i,j);
    }
    return 0;
}
运行结果:
我是父进程2781,i=10,j=13//为什么减了两次
我是子进程0,i=20,j=13
```

### 创建僵尸进程
当子程序的功能结束的时候就应当被销毁,但有时候程序会变成僵尸线程占用着重要的资源,当僵尸累计到一定数量后系统将崩溃

`僵尸进程的终止方式:`
- 传递参数并调用exit()
- main函数中执行return语句并返回值

向`exit()`传递的参数值和`return`的返回值都会传递给操作系统,而操作系统并不会销毁子进程,而是等到这两个返回值都传递进父进程后销毁,而此时等待传入的进程返回值就是僵尸进程
```cpp
int main(){
    int p_id;
    p_id=fork();
    if (p_id==0){
        exit(1);
    }else{
        sleep(30);
   }
    return 0;
}
运行结果:
root       3007  0.0  0.0   4216   356 pts/0    S    10:06   0:00 ./fz
root       3008  0.0  0.0      0     0 pts/0    Z    10:06   0:00 [fz] <defunct>

```
如果父进程一直没有主动要求获取子进程的结束状态值,操作系统会一直保存,并且让子进程处于僵尸状态

### 销毁僵尸进程
如前所述父进程如果不主动获取子进程的返回值,子进程将一直处于僵尸状态,而父进程获取子进程返回值具体方法:
```cpp
#include<unistd.h>
pid_t wait(int* statloc);
// ->成功返回子进程ID,失败返回-1
```
调用此函数时候如果已经有了子进程终止,则返回值放入了形参指向的空间地址,但是函数指向的单元需要使用宏进行分离:
- WIFEXITED 子进程正常终止返回`真`
- WEXITSTATUS 子进程的返回值
```cpp
if(WIFEXITED(status)){//判断是否正常终止
    printf("%d",WEXITSTATUS(status));//读取返回值
}
```
编写一个测试`wait()`的代码
```cpp
int main(){
    int status;
    pid_t pid=fork();
    if (pid==0){
        exit(7);
    }else{
        printf("child:%d\n",pid);
        wait(&status);
        if (WIFEXITED(status)){
            printf("%d", WEXITSTATUS(status));
        }
    }
    return 0;
}
运行结果:
child:3224
7
```
**如果没有已经结束的子进程则父进程会组赛在调用`wait()`的位置**
### 销毁僵尸进程但不阻塞
使用`wait()`函数会阻塞线程阻止正常运行,此时可以使用另一个函数`waitpid()`函数
```cpp
#include<sys/wait.h>
pid_t waitpid(pid_t pid,int* statloc,int options);
//  ->成功返回终止进程的ID,失败返回-1
pid是等待终止的进程ID,-1则是与wait相同可以是任何进程
statloc与wait一样的参数
传递头文件中的WNOHANG,防止阻塞
```

### 信号处理
我们已经知道了如何终止进程,但是进程何时终止呢,难道要一直等待吗?

**向操作系统求助**操作系统直到进程何时终止的,如果操作系统能够在子进程终止时通知父进程处理就是一个很好的方法

### signal函数与信号
操作系统在进程终止的时候会发出进程终止的信号给父进程,而如果父进程将某种结束状态的子进程处理方法设置好后,操作系统将省去通知父进程让父进程处理的操作,而是子进程终止时自动调用设置好的处理方法,使用函数`signal()`函数进行设置
```cpp
#include<signal.h>
void * (*signal(int signo,void(*func)(int)))(int);
// 返回值类型为 void(*)(int)的signal(int,void(*)(int))函数
```
其中signo的注册值:
- SIGALRM:已经通过调用alarm函数注册的时间
- SIGINT:输入了 CTRL+C
- SIGCHLD:子进程终止

接下来对注册信号进行演示:
```cpp
void timeout(int sig){
    if (sig==SIGALRM)
        puts("Time OUt!");
    alarm(2);
}
void keyDown(int sig){
    if (sig==SIGINT)
        puts("CTRL+C");
}
int main(){
    int i;
    signal(SIGALRM,timeout);
    signal(SIGINT,keyDown);
    alarm(2);
    for (int j = 0; j < 3; ++j) {
        puts("wait...");
        sleep(100);
    }
    return 0;
}
运行结果:
wait...
Time OUt!
wait...
Time OUt!
wait...
Time OUt!
```
实际运行时间只有`6秒`,因为`发生信号会唤醒由于调用sleep而阻塞的主进程`

### 使用通用的信号注册
函数`signal()`的使用只是为了兼容旧版本,而新的信号注册`sigaction()`
```cpp
int sigaction(int signo,const struct sigaction* act,struct sigaction* oldact);
// ->成功返回0,失败返回-1
```
- signo:仍然是传递信号信息
- act对应函数处理指针只是结构体放入了其他信息
- oldact获取之前的处理信息,不需要使用0
```cpp
struct sigaction{
    void (*sa_handler)(int);//存放处理函数的指针
    sigset_t sa_mask;       //初始化0
    int sa_flags;           //初始化0
}
```
演示使用`sigaction()`
```cpp
void timeout(int sig);
int main(){
    int i;
    struct sigaction act;
    act.sa_handler=timeout;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(SIGALRM,&act,0);
    alarm(2);
    for (int j = 0; j < 3; ++j) {
        puts("wait...");
        sleep(100);
    }
    return 0;
}
void timeout(int sig){
    if (sig==SIGINT)
        puts("Time OUt!");
    alarm(2);
}
运行结果:
wait...
wait...
wait...
```
### 在程序中利用信号处理技术
```cpp
void read_childPid(int sig){//设计好进程结束处理函数
    int status;
    pid_t pid= waitpid(-1,&status,WNOHANG);
    if(WIFEXITED(status)){
        printf("child Pid:%d\n",pid);
        printf("child Send:%d\n", WEXITSTATUS(status));
    }
}
int main(){
    pid_t pid;
    struct sigaction act;
    act.sa_handler=read_childPid;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(SIGCHLD,&act,0);//绑定信号处理
    pid=fork();
    if (pid==0){//子进程
        puts("child!");
        sleep(3);
        exit(24);
    }else{
        printf("child id:%d\n",pid);
        pid=fork();
        if (pid==0){
            puts("child!");
            sleep(3);
            exit(12);
        }else{
            printf("child id:%d\n",pid);
            for (int i = 0; i < 3; ++i) {
                puts("wait...");
                sleep(5);
            }
        }
    }
    return 0;
}
运行结果：
child id:2363
child id:2364
wait...
child!
child!
child Pid:2363
child Send:24
wait...
child Pid:2364
child Send:12
wait...
```
### 基于多任务的并发服务器
之前的回声系统都是一对一服务，现在对服务器扩展使得进行一对多服务，在父进程接受连接请求，在子进程中进行连接
- 第一阶段：回声服务器通过调用accept函数受理请求连接
- 第二阶段：此时获取的套接字文件描述创建并传递给子进程
- 第三阶段：子进程利用传递进来的文件描述符进行服务
```cpp
void read_childPid(int sig){
    int status;
    pid_t pid= waitpid(-1,&status,WNOHANG);
    printf("child Pid:%d\n",pid);
}
int main(int argc,char* argv[]){
    int sock,clint;                 //定义套接字
    struct sockaddr_in sever_addr,client_addr;//定义地址存储结构体
    socklen_t client_len;               //定义结构体长度
    
    sock= socket(PF_INET,SOCK_STREAM,0);//创建套接字
    //初始化服务器地址
    sever_addr.sin_family=PF_INET;
    sever_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    sever_addr.sin_port= htons(atoi(argv[1]));

    //初始化信号处理
    pid_t pid;
    struct sigaction act;
    act.sa_handler=read_childPid;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(SIGCHLD,&act,0);

    //绑定套接字和地址开始监听
    bind(sock,(struct sockaddr*)&sever_addr,sizeof (sever_addr));
    listen(sock,5);

    //设置好缓冲区
    int str_len;
    char buffer[1024];
    while (1){
        
        client_len= sizeof(client_addr);
        //与客户端建立连接
        clint= accept(sock,(struct sockaddr*)&client_addr,&client_len);
        if (clint==-1){
            //建立失败回到开头等待连接
            puts("accept ERROR!");
            continue;
        }else{
            puts("connected...");
        }
        //创建一个子进程
        pid=fork();
        if (pid==-1){
            //子进程创建失败关闭客户端套接字
            close(clint);
            continue;
        }
        if (pid==0){
            //子进程执行
            close(sock);//关闭服务端套接字避免服务接入子进程
            //回声
            while((str_len=read(clint,buffer,1024))!=0) {
                buffer[str_len]=0;
                write(clint, buffer, str_len);
            }
            //关闭套接字
            close(clint);
            puts("client end!");
            return 0;
        }else{
            //主进程放弃和客户端的连接
            close(clint);
        }
    }
    return 0;
}
```

### 分割TCP的IO程序
将IO操作进行进程分离方便了编程简化了逻辑`主进程只负责读数据`和`创建子进程负责写数据`,这样做可以提高频繁交换数据的程序性能

## 第十一章 进程间通信
进程间通信意味着两个不同进程间可以交换数据,但是又是如何做到的呢?

### 对进程间通信的基本理解
假如进程A和进程B进行通信,进程A将要传达的信息放入一片变量内存空间中并且告诉进程B,我已经将要告诉你的内容放到了某片空间中你可以去查看,这样通过拥有一片相同的空间就完成了进程间的通信

### 通过管道实现进程间通信

管道并非属于进程资源而是和套接字一样属于操作系统.
```cpp
#include<unistd.h>
int pipe(int filedes[2]);
// ->成功返回0,失败返回-1
filedex[0]表示管道的出口
filedex[1]表示管道的入口
```
以长度为2的int数组表示两个文件描述符,之后通过文件描述符进行沟通
``` cpp
int main(){
    pid_t pid;
    char message[]={"hello word!!\n"};//要发送的信息
    char buffer[128];//接收信息缓冲区
    int fpipe[2];
    pipe(fpipe);
    pid=fork();
    if (pid==0){
        write(fpipe[1],message, sizeof(message));//写入管道
    }else{
        int str_len=read(fpipe[0],buffer,128);//读取管道
        buffer[str_len]=0;
        puts(buffer);//打印
    }
    return 0;
}
```

### 通过管道进行双向通信
管道并不分出入而是一个谁都可以去读取存入的空间,第一个进行读操作的将会将数据取走,所以如果要进行进程间的管道通信要使用两个管道.

### 运用进程间通信
把回声客户端的数据保存到一个文件中去,子进程负责将读入的数据写入到本地文件,主进程负责读数据,另一个进程负责回声0