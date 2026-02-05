#include "shell.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

void Shell::copyFile(const string&src,const string& dest){
    //open file
    int src_fd=open(src.c_str(),O_RDONLY);
    if(src_fd<0){
        perror("open source");
        return;
    }

    //open/create destination file

    int dest_fd=open(dest.c_str(),
                    O_WRONLY|O_CREAT|O_TRUNC,
                    0644);
    

    if(dest_fd <0){
        perror("open destination");
        close(src_fd);
        return;
    }

    const int BUFFER_SIZE=4096;
    char buffer[BUFFER_SIZE];
    ssize_t bytes;

    //read -> write loop
    while((bytes=read(src_fd,buffer,BUFFER_SIZE))>0){
        if(write(dest_fd,buffer,bytes)!=bytes){
            perror("write");
            break;
        }
    }
    if(bytes<0)
        perror("read");
    close(src_fd);
    close(dest_fd);
}