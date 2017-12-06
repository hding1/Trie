#ifndef Word_hpp
#define Word_hpp
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Word{
public:
    //Contructor
    Word();
    Word(string word);
    Word(string word, int weight);
    //Modifier
    void setWord(string word);
    void setWeight(int weight);
    void insertWord(string wordName);
    void setRoot();
    //Observer
    bool isRoot();
    int getWeight();
    Word* find(string wordName);
    string getWord();
    vector<Word*> getWordList();
    int size();
private:
    bool root=false;
    string word;
    int wordCount;
    int weight;
    vector<Word*> list;
};
#endif /* Word_hpp */


