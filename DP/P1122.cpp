#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int INF=-1e9+7;
void dfs(vector<vector<int>>& edge,vector<ll> &dp,vector<ll>& pv,int now,int fa){
	dp[now]=pv[now];
	for(int to:edge[now]){
		if(to!=fa){
			dfs(edge,dp,pv,to,now);
			if(dp[to]>0){
				dp[now]+=dp[to];
			}
		}
	}
}



int main(){
	int n;cin>>n;ll ans=INF;
	vector<ll> point_values(n+1);
	vector<vector<int>> edge(n+1,vector<int>());
	
	
	for(int i=1;i<=n;i++){
		cin>>point_values[i];
	}
	
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	vector<ll> dp(n+1,0);
	dp[1]=1;
	dfs(edge,dp,point_values,1,0);
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
	
}
