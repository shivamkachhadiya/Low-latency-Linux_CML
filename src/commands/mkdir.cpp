#include "shell.hpp"
#include <sys/stat.h>
#include <iostream>
#include <cerrno>

void Shell::makeDirectory(const std::string& path)
{
    if(mkdir(path.c_str(), 0755) != 0)
    {
        perror("mkdir");
    }
}
