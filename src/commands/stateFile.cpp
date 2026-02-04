#include "shell.hpp"
#include <iostream>
#include <sys/stat.h>

void Shell::stateFile(const std::string& path){
    struct stat info;

    if(stat(path.c_str(), &info) != 0){
        perror("stat");
        return;
    }

    std::cout << "Size: " << info.st_size << " Bytes\n";
    std::cout << "Inode: " << info.st_ino << "\n";

    std::cout << ((info.st_mode & S_IRUSR) ? "r" : "-");
    std::cout << ((info.st_mode & S_IWUSR) ? "w" : "-");
    std::cout << ((info.st_mode & S_IXUSR) ? "x" : "-");
    std::cout << "\n";
}
