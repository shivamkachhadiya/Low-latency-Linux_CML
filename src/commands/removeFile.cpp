#include "shell.hpp"
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
void Shell::removeFile(const string& path){

    struct stat st;
    if (lstat(path.c_str(), &st) == -1) {
        perror("rm");
        return;
    }

    if (S_ISDIR(st.st_mode))
        rmdir(path.c_str());
    else
        unlink(path.c_str());
 
}