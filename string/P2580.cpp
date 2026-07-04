#include <bits/stdc++.h>
using namespace std;

struct Node{
    char val;bool isEnd;
    vector<Node*> children;
    Node(char c){
        val=c;
        isEnd=false;
        children.resize(26);
    }

};

