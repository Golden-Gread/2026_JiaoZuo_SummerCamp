#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    char val;
    vector<int> children;
    TrieNode(char c) : val(c), children(26, -1) {}
};

