#include "shell.hpp"

#include <iostream>
#include <fcntl.h>      // open
#include <unistd.h>     // close

using namespace std;

void Shell::touchFile(const string& filename)
{
    // open file
    int fd = open(filename.c_str(), O_CREAT | O_WRONLY, 0644);

    if(fd == -1)
    {
        perror("touch");
        return;
    }

    close(fd);
}
