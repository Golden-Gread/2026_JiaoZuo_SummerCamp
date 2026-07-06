#include <bits/stdc++.h>
using namespace std;

struct Node {
    int children[26];
    bool isEnd;
    int fail;
};

vector<Node> trie;
int tot=0;

