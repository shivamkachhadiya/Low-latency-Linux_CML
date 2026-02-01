#include "shell.hpp"
#include <iostream>
#include <unistd.h>
#include <limits.h>
using namespace std;

void Shell::printWorkingDirectory(){
    char buffer[PATH_MAX];
    if(getcwd(buffer,sizeof(buffer))!=nullptr){
        cout<<buffer<<endl;
    }else{
        perror("getcwd");
    }
}

void Shell::run(){
    string command;
    while(true){
        cout<<"LINUX_CML>";
        cin>>command;

        if(command=="pwd"){
            printWorkingDirectory();
        }
        else if(command=="exit"){
            break;
        }else{
            cout<<"unknown command \n";
        }
    }
}