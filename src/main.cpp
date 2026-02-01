#include <iostream>
#include "shell.hpp"
int main() {
    std::cout << "Linux File Explorer Started...\n";
    Shell shell;
    shell.run();
    return 0;
}
