#include "include.hpp"
using namespace std;

void Shell::listDirectory(){
    DIR* dir=opendir(".");
    //. means current file. take a control. return pointer. storee in DIR*
    if(dir==nullptr){
        perror("ls");
        return;
    }
    //internally dirent in linux
//     struct dirent {
//          ino_t d_ino;
//          char d_name[256];
// };   Each file inside folder is represented by: dirent

    struct dirent* entry;

    while((entry=readdir(dir))!=nullptr){
        cout<<entry->d_name<<" ";
    }
    cout<<endl;
    closedir(dir);
}