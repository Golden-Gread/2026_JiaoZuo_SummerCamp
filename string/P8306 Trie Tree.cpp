#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int isEnd;
    TrieNode() : isEnd(false) {}
    int dfs(){
        for(auto child:children){
            if(child.second!=nullptr and child.second->isEnd!=0){
                return child.second->dfs()+child.second->isEnd;
            }else if(child.second!=nullptr){
                return child.second->dfs();
            }
            return 0;
        }
    }
};



void insert(TrieNode* root,string s){
    TrieNode* cur = root;
    for(char c:s){
        if(cur->children.find(c)==cur->children.end()){
            cur->children[c] = new TrieNode();
        }
        cur = cur->children[c];
    }
    cur->isEnd++;
}

int find(TrieNode* cur,string s){
    for(char c:s){
        if(cur->children.find(c)==cur->children.end()) return 0;
        cur = cur->children[c];
    }

    return cur->dfs();
}

int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int n,q;
        TrieNode* root = new TrieNode();
        cin>>n>>q;
        for(int j=1;j<=n;j++){
            string s;cin>>s;
            insert(root,s);
        }
        for(int j=0;j<q;j++){
            string s;cin>>s;
            cout<<find(root,s)<<endl;
        }
       
    }
}

