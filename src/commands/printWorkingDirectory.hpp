#include "include.hpp"
using namespace std;

void Shell::printWorkingDirectory(){
    char buffer[PATH_MAX];
    if(getcwd(buffer,sizeof(buffer))!=nullptr){
        cout<<buffer<<endl;
    }else{
        perror("getcwd");
    }
}
