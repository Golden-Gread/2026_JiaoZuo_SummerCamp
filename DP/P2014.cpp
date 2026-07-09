#include<bits/stdc++.h>
using namespace std;
int m;
void dfs(vector<vector<int>>& tree,vector<vector<int>>& dp,int now,int fa){
	for(int to:tree[now]){
		if(to!=fa){
			dfs(tree,dp,to,now);
			for(int j=m+1;j>=1;j--){
				for(int k=0;k<j;k++){
					dp[now][j]=max(dp[now][j],dp[now][j-k]+dp[to][k]);
				}
			}
		}
	}
}


int main(){
	int n;cin>>n>>m;
	
	vector<vector<int>> tree(n+1,vector<int>());
	vector<int> class_values(n+1,0);
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	
	for(int i=1;i<=n;i++){
		int fa;cin>>fa>>dp[i][1];
		tree[fa].push_back(i);
	}
	
	dfs(tree,dp,0,0);
	
	cout<<dp[0][m+1];
	return 0;
}
