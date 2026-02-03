#include "include.hpp"
using namespace std;


void Shell::changeDirectory(const string& path){
    if(chdir(path.c_str())!=0){
        perror("cd");
    }
}
