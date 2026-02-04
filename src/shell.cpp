#include "include.hpp"
using namespace std;
void Shell::run(){
    string command,arg;
    while(true){
        cout<<"LINUX_CML>";
        cin>>command;

        if(command=="pwd"){
            printWorkingDirectory();
        }else if(command=="help"){
            printHelp();
        }else if(command=="cd"){
            cin>>arg;
            changeDirectory(arg);
        }
        else if(command=="exit"){
            break;
        }else if(command=="ls"){
            listDirectory();
        }else if(command=="stat"){
            string file;
            cin>>file;
            stateFile(file);
        }else{
            cout<<"unknown command \n";
        }
    }
}


