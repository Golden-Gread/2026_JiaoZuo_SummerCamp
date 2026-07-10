#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+7;

void DFS(int now,int fa,vector<vector<int>>& tree,vector<vector<int>>& dp){
    dp[now][1]=1;dp[now][0]=0;
    
    for(int i)
}


int main(){
    int n;cin>>n;
    vector<vector<int>> tree(n+1,vector<int>());

    for(int i=0;i<n;i++){
        int u,k;cin>>u>>k;
        for(int j=0;j<k;j++){
            int v;cin>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    
    
}