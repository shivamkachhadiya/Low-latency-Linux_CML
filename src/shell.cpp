#include "shell.hpp"
#include <iostream>
#include <unistd.h>
#include <cerrno>
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

void Shell::printHelp(){
    cout<<"commands:\n";
    cout<<"pwd - print directory\n";
    cout<<"help -show help\n";
    cout<<"quit -quit shell\n";
}


void Shell::changeDirectory(const string& path){
    if(chdir(path.c_str())!=0){
        perror("cd");
    }
}



void Shell::run(){
    string command,arg;
    while(true){
        cout<<"LINUX_CML>";
        cin>>command;

        if(command=="pwd"){
            printWorkingDirectory();
        }else if(command=="help"){
            printHelp();
        }else if(command=="cd"){
            cin>>arg;
            changeDirectory(arg);
        }
        else if(command=="exit"){
            break;
        }else{
            cout<<"unknown command \n";
        }
    }
}


