#include "Tree.hpp"
#include <iostream>
#include <sstream>
Tree::Tree()
{
    root = new Word("Root");
    root->setRoot();
    maxNode = root;
    size=0;
    maxSize = 0;
}
void Tree::insert(vector<string> list,int weight){
    insertPrivate(root, list, weight);
}
void Tree::insertPrivate(Word* node,vector<string> list,int weight){
    string word = list[0];
    if(list.size()<=1&&!(list[0].empty())){
        node->insertWord(list[0]);
        if(!node->isRoot()&&node->size()>maxSize){
            maxNode = node;
            maxSize=node->size();
        }else if(maxNode->isRoot()&&maxSize==0){
            maxNode = node->find(word);
        }
        node->find(list[0])->setWeight(weight);
    }else if(node!=NULL&&list.size()>1&&!(list[0].empty())){
        node->insertWord(list[0]);
        if(!node->isRoot()&&node->size()>maxSize){
            maxNode = node;
            maxSize=node->size();
        }else if(maxNode->isRoot()&&maxSize==0){
            maxNode = node->find(word);
        }
        list.erase(list.begin());
        insertPrivate(node->find(word),list,weight);
    }
}
map<int,string> Tree::getSentences(Word* key){
    map<int,string> result;
    string chain="";
    if(key==NULL){
    }else{
        vector<Word*> temp = key->getWordList();
        for(int i = 0; i<temp.size();i++){
            getSentencesPrivate(result, chain, temp[i]);
        }
    }
    return result;
}

void Tree::getSentencesPrivate(map<int,string> &dic, string sentence, Word* key){
    if(key->getWeight()==-1){
        vector<Word*> temp = key->getWordList();
        sentence+=key->getWord()+" ";
        for(int i=0;i<temp.size();i++){
            getSentencesPrivate(dic,sentence,temp[i]);
        }
    }else{
        sentence+=key->getWord();
        dic.insert(pair<int,string>(key->getWeight(),sentence));
        if(key->size()!=0){
            vector<Word*> temp = key->getWordList();
            sentence+=" ";
            for(int i=0;i<temp.size();i++){
                getSentencesPrivate(dic,sentence,temp[i]);
            }
        }
    }
}
void Tree::print(string word){
    Word* key = root;
    queue<string> result;
    istringstream iss(word);
    for(string s; iss >> s;){
        result.push(s);
    }
    while(!result.empty()){
        if(key->find(result.front())==NULL){
            cout<<"No valid completion"<<endl;
            printMaxNode();
            return;
        }else{
            key = key->find(result.front());
            result.pop();
        }
    }
    if(key==NULL){
        cout<<"No valid completion"<<endl;
    }else{
        map<int,string> sentences = getSentences(key);
        for(auto pos1=sentences.rbegin();pos1!=sentences.rend();pos1++){
            cout<<pos1->second<<endl;
        }
    }
    printMaxNode();
}
void Tree::printMaxNode(){
    cout<<maxNode->getWord()<<" "<<maxSize<<endl;
}
Word* Tree::getRoot(){
    return root;
}

int Tree::getsize(){
    return size;
}

