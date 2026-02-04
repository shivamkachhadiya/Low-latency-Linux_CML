#include "shell.hpp"
#include <iostream>

void Shell::printHelp(){
    std::cout << "commands:\n";
    std::cout << "pwd\ncd <dir>\nls\nstat <file>\necho <text>\nexit\n";
}
