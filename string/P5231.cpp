#include <bits/stdc++.h>
using namespace std;

struct Node {
    int children[26];
    bool isEnd;
    int fail;
    Node(): isEnd(false), fail(-1) {memset(children,0,sizeof(children));}
};

vector<Node> trie;
int tot=0;

void insert(string s) {
    int cur=0;
    for (char c:s) {
        int idx=c-'A';
        if(trie[cur].children[idx]==0){
            trie.push_back(Node());
            trie[cur].children[idx]=tot++;
        }
        cur=trie[cur].children[idx];
    }

    trie[cur].isEnd=true;

}

void build() {
    queue<int> q;

}