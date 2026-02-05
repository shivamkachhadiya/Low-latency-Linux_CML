#include "shell.hpp"
#include <iostream>

void Shell::showHistory(){
    for(size_t i=0;i<historyList.size();++i){
        cout<<i+1<<" "<<historyList[i]<<"\n";
    }
}