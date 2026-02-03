#pragma once
#include <string>
using namespace std;
class Shell {
public:
    void run();

private:
    void printWorkingDirectory();
    void printHelp();
    void changeDirectory(const string& path);
    void listDirectory();
};
