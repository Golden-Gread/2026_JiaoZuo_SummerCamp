#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
vector<int> e[10005],e_new[10005];
int dfn[10005],low[10005],t,bssc[10005],cnt,scc_sum[10005];
int f[10005],in[10005],ans,in_new[10005];
stack<int> stk;
bool instk[10005],vis[10005]={0};
void dfs(int u){
	t++;
	low[u]=dfn[u]=t;
	stk.push(u);
	instk[u]=1;
	for(auto v:e[u]){
		if(!vis[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(instk[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		while(stk.top()!=u){
			bssc[stk.top()]=u;
			instk[stk.top()]=0;
			scc_sum[u]+=a[stk.top()];
			stk.pop();
		}
		bssc[u]=u;
		instk[u]=0;
		scc_sum[u]+=a[u];
		stk.pop();
	}
	return;
}
void build(){
	for(int u=1;u<=n;u++){
		for(auto v:e[u]){
			if(bssc[u]!=bssc[v]){
				e_new[bssc[u]].push_back(bssc[v]);
				in_new[bssc[v]]++;
			}
		}
	}
}
queue<int> q;
void dp(){
	for(int i=1;i<=n;i++){
		if(!in_new[i]&&i==bssc[i]){
			q.push(i);
			f[i]=scc_sum[i];
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:e_new[u]){
			f[v]=max(f[v],f[u]+scc_sum[v]);
			in_new[v]--;
			if(!in_new[v]){
				q.push(v);
			}
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		in[v]++;
	}

	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			dfs(i);
		}
	}
	build();
	dp();
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
