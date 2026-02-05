#include "shell.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
void Shell::execCommand(const vector<string>& tokens)
{
    pid_t pid = fork();

    if(pid == 0) // child
    {
        vector<char*> argv;

        for(const auto& t : tokens)
            argv.push_back(const_cast<char*>(t.c_str()));

        argv.push_back(nullptr);   //  VERY IMPORTANT

        execvp(argv[0], argv.data());

        perror("exec failed");
        exit(1);
    }
    else if(pid > 0) // parent
    {
        waitpid(pid, nullptr, 0);
    }
    else
    {
        perror("fork failed");
    }
}