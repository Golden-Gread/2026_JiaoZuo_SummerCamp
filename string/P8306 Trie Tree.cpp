#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
    int dfs(){
        for(auto child:children){
            if(child.second!=nullptr and child.second->isEnd){
                return child.second->dfs()+1;
            }        
        }
    }
};

TrieNode* root = new TrieNode();

void insert(string s){
    TrieNode* cur = root;
    for(char c:s){
        if(cur->children.find(c)==cur->children.end()){
            cur->children[c] = new TrieNode();
        }
        cur = cur->children[c];
    }
    cur->isEnd = true;
}

int find(TrieNode* cur,string s){
    for(char c:s){
        if(cur->children.find(c)==cur->children.end()) return -1;
        cur = cur->children[c];
    }

    return cur->dfs() + 1;
}

int main(){
    int t;cin>>t;
    
}

