//
// Created by 36302 on 2023/5/1.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int fd;//文件描述符
    //打开文件以只读创建方式
    fd=open("write",O_CREAT|O_WRONLY);
    if(fd==-1){
        puts("GG\n");
        return 0;
    }
    printf("fd:%d\n",fd);
    char buf[]="qwertyuiopasdfghjk\n";
    if(write(fd,buf, sizeof(buf))==-1){
        puts("GG\n");
        return 0;
    }
    close(fd);
    return 0;
}