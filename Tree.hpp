#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <string>
#include "Word.hpp"
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Tree
{
public:
    Tree();
    Tree(Word* word);
    void insert(vector<string> list,int weight);
    void inOrder();
    Word* getRoot();
    Word* find(string word);
    map<int,string> getSentences(Word* key);
    int getsize();
    void print(string word);
    void printMaxNode();
private:
    void getSentencesPrivate(map<int,string> &dic, string sentence,Word* key);
    void insertPrivate(Word* node,vector<string> list,int weight);
    Word* root;
    int size;
    int maxSize;
    Word* maxNode;
};
#endif /* Tree_hpp */
