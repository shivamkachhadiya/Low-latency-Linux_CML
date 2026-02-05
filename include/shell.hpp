#pragma once

#include <string>
#include <vector>
using namespace std;
class Shell {
public:
    void run();

private:
    void printWorkingDirectory();
    void printHelp();
    void changeDirectory(const std::string& path);
    void listDirectory();
    void stateFile(const std::string& path);
    void echo(const std::vector<std::string>& args);
    void makeDirectory(const std::string& path);
};
