#include "shell.hpp"
#include <iostream>
#include <unistd.h>
#include <limits.h>

void Shell::printWorkingDirectory(){
    char buffer[PATH_MAX];

    if(getcwd(buffer, sizeof(buffer))){
        std::cout << buffer << "\n";
    } else {
        perror("getcwd");
    }
}
