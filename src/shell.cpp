#include "shell.hpp"
#include <iostream>
#include <sstream>
using namespace std;
void Shell::run() {
    string line;

    while(true) {
        cout << "LINUX_CML> ";

        getline(cin, line);
        historyList.push_back(line);
        if(line.empty()) continue;

        stringstream ss(line);
        vector<string> tokens;
        string temp;

        while(ss >> temp){
            tokens.push_back(temp);
        }

        string command = tokens[0];
        vector<string> args(tokens.begin()+1, tokens.end());

        if(command == "pwd") printWorkingDirectory();
        else if(command == "help") printHelp();
        else if(command == "cd" && !args.empty()) changeDirectory(args[0]);
        else if(command == "ls") listDirectory();
        else if(command == "stat" && !args.empty()) stateFile(args[0]);
        else if(command == "echo") echo(args);
        else if(command == "cat") catFile(args[0]);
        else if(command == "mkdir") {
            if(!args.empty())
                makeDirectory(args[0]);
        }
        else if(command ==  "touch")touchFile(args[0]);

        else if(command == "rm") removeFile(args[0]);
        else if(command == "cp"){
            if(args.size()==2){
                copyFile(args[0],args[1]);
            }else{
                cout<<"usage : cp <src> <dest> \n";
            }
        }
        else if(command == "history"){
            showHistory();
        }
        else if(command == "exit") break;

        else execCommand(tokens);
    }
}
