//
//  main.cpp
//  CS130a Programming Assignment
//
//  Created by Peter Ding on 10/30/17.
//  Copyright © 2017 Peter Ding. All rights reserved.
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Tree.hpp"
#include <sstream>
using namespace std;
bool isNumber(string str);
bool isNumber(string str){
    for(int i = 0; i<str.length();i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}
int main(int argc, char* argv[])
{
    Tree* myTree = new Tree();
    string line = " ";
    while(getline(cin,line)&&line.length()>0){
        stringstream ss(line);
        int weight=0;
        string word_weight;
        ss>>word_weight;
        if(isNumber(word_weight)){
            weight = stoi(word_weight);
        }else{
            cout<<"invalid input"<<endl;
            return 0;
        }
        string word="";
        vector<string> words ={};
        do{
            ss>>word;
            words.push_back(word);
        }while(!ss.eof());
        myTree->insert(words,weight);
    }
    string keyword;
    getline(cin,keyword);
    myTree->print(keyword);
    return 0;
}
