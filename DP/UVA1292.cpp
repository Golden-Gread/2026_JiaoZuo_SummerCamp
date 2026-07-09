#include <bits/stdc++.h>
using namespace std;

void dfs(int now,vector<vector<int>>& tree,vector<vector<int>>& dp){
    dp[now][1]=1;
    for(int child:tree[now]){
        dfs(child,tree,dp);
        dp[now][0]+=dp[child][1];
        dp[now][1]+=min(dp[child][0],dp[child][1]);
    }
}



int main(){
    int n;
    vector<vector<int>> tree;
    vector<int> deg;
    vector<vector<int>> dp;
    while(scanf("%d\n",&n)!=EOF){
        tree.resize(n+1,vector<int>());
        deg.resize(n+1,0);
        dp.resize(n+1,vector<int>(2,0));

        int u,childNum;
        for(int i=0;i<n;i++){
            scanf("%d:(%d)",&u,&childNum);
            for(int j=0;j<childNum;j++){
                int child;
                scanf(" %d",&child);
                deg[child]++;
                tree[u].push_back(child);
            }
            scanf("\n");
        }
        int rt;
        for(int i=1;i<=n;i++){
            if(deg[i]==0){
                rt=i;
                dfs(i,tree,dp);
                break;
            }
        }
        printf("%d\n",min(dp[rt][0],dp[rt][1]));
        tree.clear();
        deg.clear();
        dp.clear();
    }
}