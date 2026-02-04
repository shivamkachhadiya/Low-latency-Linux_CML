#include "include.hpp"
using namespace std;

void Shell::stateFile(const string& path){
    struct stat info;

    if(stat(path.c_str(),&info)!=0){
        perror("stat");
        return;
    }
    cout<<"Size : "<<info.st_size<<" Bytes\n";
    cout<<"Inode : "<<info.st_ino<<"\n";
    
    //permissions
    cout<<"permisssions..."<<endl;
    cout<<((info.st_mode & S_IRUSR)? "r" : "-");
    cout<<((info.st_mode & S_IWUSR)? "w" : "-");
    cout<<((info.st_mode & S_IXUSR)? "x" : "-");
    cout<<endl;

    if(S_ISDIR(info.st_mode))cout<<"Type : Directory\n";
    else if(S_ISREG(info.st_mode))cout<<"Type : Reguler File\n";
}