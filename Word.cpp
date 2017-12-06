#include <stdio.h>
//Implement for word node
#include "Word.hpp"
using namespace std;

//Contructor
Word::Word()
{
    wordCount=0;
    weight =-1;
}
Word::Word(string word)
{
    this->word = word;
    weight = -1;
    wordCount=0;
}
Word::Word(string word, int weight)
{
    this->word = word;
    this->weight = weight;
    wordCount=0;
}

//Modifier
void Word::setRoot(){
    root = true;
}
void Word::setWord(string word)
{
    this->word = word;
}
void Word::setWeight(int weight){
    this->weight = weight;
}
void Word::insertWord(string wordName)
{
    Word* temp = find(wordName);
    if(temp==NULL){
        list.push_back(new Word(wordName));
        wordCount++;
    }else{
        
    }
}

//Observer
int Word::getWeight(){
    return weight;
}
bool Word::isRoot(){
    return root;
}
string Word::getWord()
{
    return word;
}
vector<Word*> Word::getWordList(){
    return list;
}
Word* Word::find(string wordName){
    for(int i = 0; i<list.size();i++){
        if(list[i]->getWord()==wordName){
            return list[i];
        }
    }
    return NULL;
}
int Word::size(){
    return list.size();
}

