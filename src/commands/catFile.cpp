#include "shell.hpp"
#include <fcntl.h>
#include <unistd.h> //for read(),write(),close()
#include <iostream>

void Shell::catFile(const string& path){
    //open file read only
    int fd=open(path.c_str(),O_RDONLY);

    if(fd==-1){
        perror("open");
        return;
    }

    const size_t BUFFER_SIZE=4096; //linux page size=2kb
    char buffer[BUFFER_SIZE];

    ssize_t bytes;

    cout<<"=====================FILE CONTAINS============================"<<endl;

    while((bytes=read(fd,buffer,BUFFER_SIZE))>0){
        write(1,buffer,bytes);
    }
    
    if(bytes==-1){
        perror("read");
    }

    close(fd);
    cout<<"=====================END - OF - FILE============================"<<endl;
}