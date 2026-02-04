#include "shell.hpp"
#include <unistd.h>
#include <iostream>

void Shell::changeDirectory(const std::string& path){
    if(chdir(path.c_str()) != 0){
        perror("cd");
    }
}
