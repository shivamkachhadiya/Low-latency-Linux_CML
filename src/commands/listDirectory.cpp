// #pragma once

// #include "shell.hpp"
// #include <iostream>
// #include <unistd.h>
// #include <cerrno>
// #include <limits.h>
// //state file includes
// using namespace std;

// void Shell::listDirectory(){
//     DIR* dir=opendir(".");
//     //. means current file. take a control. return pointer. storee in DIR*
//     if(dir==nullptr){
//         perror("ls");
//         return;
//     }
//     //internally dirent in linux
// //     struct dirent {
// //          ino_t d_ino;
// //          char d_name[256];
// // };   Each file inside folder is represented by: dirent

//     struct dirent* entry;

//     while((entry=readdir(dir))!=nullptr){
//         cout<<entry->d_name<<" ";
//     }
//     cout<<endl;
//     closedir(dir);
// }

#include "shell.hpp"
#include <iostream>
#include <dirent.h>

void Shell::listDirectory(){
    DIR* dir = opendir(".");
    if(!dir){
        perror("ls");
        return;
    }

    struct dirent* entry;

    while((entry = readdir(dir)) != nullptr){
        std::cout << entry->d_name << " "<<endl;
    }

    std::cout << "\n";
    closedir(dir);
}
