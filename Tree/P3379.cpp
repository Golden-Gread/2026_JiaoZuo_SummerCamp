#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 7;

vector<int> G[MAXN];
int pval[MAXN];
int n,m,root,MOD;

int fa[MAXN],depth[MAXN],siz[MAXN],son[MAXN];//son记录重儿子
int top[MAXN],dfn[MAXN],rnk[MAXN],dfs_cnt=0; //rnk反向映射dfn

void dfs1(int now,int father){
	fa[now]=father;
	depth[now]=depth[father]+1;
	siz[now]=1;
	int maxS=-1;
	for(int to:G[now]){
		if(to==father) continue;
		dfs1(to,now);
		siz[now]+=siz[to];
		if(siz[to]>maxS){
			maxS=siz[to];
			son[now]=to;
		}
	}
}

void dfs2(int now,int topf){
	dfn[now]=++dfs_cnt;
	rnk[dfs_cnt]=now;
	top[now]=topf;
	if(!son[now]) return;
	dfs2(son[now],topf);
	for(int to:G[now]){
		if(to==fa[now] or to==son[now]) continue;
		dfs2(to,to);  //构建新重链
	}
}

int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]]){
			swap(x,y);
		}
		x=fa[top[x]];
	}
	return (depth[x]<depth[y])?x:y;
	
}

int main(){
	cin>>n>>m>>root;
	for(int i=1;i<=n;i++){
		cin>>pval[i];
	}
	
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs1(root,1);
	dfs2(root,root);
	
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		cout<<LCA(x,y)<<endl;
	}
	
	return 0;
	
	
}
