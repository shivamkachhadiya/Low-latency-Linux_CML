#include "shell.hpp"
#include <iostream>
#include <sstream>

void Shell::run() {
    std::string line;

    while(true) {
        std::cout << "LINUX_CML> ";

        std::getline(std::cin, line);
        if(line.empty()) continue;

        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string temp;

        while(ss >> temp){
            tokens.push_back(temp);
        }

        std::string command = tokens[0];
        std::vector<std::string> args(tokens.begin()+1, tokens.end());

        if(command == "pwd") printWorkingDirectory();
        else if(command == "help") printHelp();
        else if(command == "cd" && !args.empty()) changeDirectory(args[0]);
        else if(command == "ls") listDirectory();
        else if(command == "stat" && !args.empty()) stateFile(args[0]);
        else if(command == "echo") echo(args);
        else if(command == "exit") break;
        else std::cout << "unknown command\n";
    }
}
