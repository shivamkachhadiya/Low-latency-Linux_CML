#include "shell.hpp"
#include <iostream>

void Shell::echo(const std::vector<std::string>& args){
    for(const auto& s : args){
        std::cout << s << " ";
    }
    std::cout << "\n";
}
