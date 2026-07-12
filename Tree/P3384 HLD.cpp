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

//----------------线段树实现-----------------

ll tree[MAXN*4]={0},lazy[MAXN*4]={0};

void build(int node,int l,int r){
	if(l==r){
		tree[node]=pval[rnk[l]]%MOD;
		return;
	}
	int mid=(l+r)>>1;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node]=(tree[node*2]+tree[node*2+1])%MOD;
}

//标记下放

void pushDown(int node,int l,int r){
	if(lazy[node]==0) return;
	int mid=(l+r)>>1;
	int rs=node*2+1,ls=node*2;
	
	lazy[ls]=(lazy[ls]+lazy[node])%MOD;
	tree[ls]=(tree[ls]+lazy[node]*(mid-l+1))%MOD;
	
	lazy[rs]=(lazy[rs]+lazy[node])%MOD;
	tree[rs]=(tree[rs]+lazy[node]*(r-mid))%MOD;
	
	lazy[node]=0;
}

void rangeAdd(int node,int l,int r,int L,int R,ll val){
	if(L<=l and r<=R){
		lazy[node]=(lazy[node]+val)%MOD;
		tree[node]=(tree[node]+val*(r-l+1))%MOD;
		return;
	}
	
	pushDown(node,l,r);
	int mid=(l+r)>>1;

	if(L<=mid) rangeAdd(node<<1,l,mid,L,R,val);
	if(R>mid) rangeAdd(node<<1|1,mid+1,r,L,R,val);
	tree[node]=(tree[node<<1]+tree[node<<1|1])%MOD;
}

ll query(int node,int l,int r,int L,int R){
	if(L<=l and r<=R){
		return tree[node];
	}
	
	pushDown(node,l,r);
	int mid=(l+r)>>1;
	ll sum=0;
	if(L<=mid) sum=(sum+query(node<<1,l,mid,L,R))%MOD;
	if(R>mid) sum=(sum+query(node<<1|1,mid+1,r,L,R))%MOD;
	return sum;
}

//-----------树剖-----------

void pathChange(int x,int y,ll val){
	val%=MOD;
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]]) swap(x,y);
		rangeAdd(1,1,n,dfn[top[x]],dfn[x],val);
		x=fa[top[x]];
	}
	if(depth[x]>depth[y]) swap(x,y);
	rangeAdd(1,1,n,dfn[x],dfn[y],val);
}

ll pathQuery(int x,int y){
	ll res=0;
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]]) swap(x,y);
		res=(res+query(1,1,n,dfn[top[x]],dfn[x]))%MOD;
		x=fa[top[x]];
	}
	if(depth[x]>depth[y]) swap(x,y);
	res=(res+query(1,1,n,dfn[x],dfn[y]))%MOD;
	return res;
}

void subtreeAdd(int x,ll val){
	val%=MOD;
	rangeAdd(1,1,n,dfn[x],dfn[x]+siz[x]-1,val);
}

ll subtreeQuery(int x){
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}

int main(){
	cin>>n>>m>>root>>MOD;
	for(int i=1;i<=n;i++){
		cin>>pval[i];
		pval[i]%=MOD;
	}
	
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs1(root,0);
	dfs2(root,root);
	
	build(1,1,n);
	
	for(int i=1;i<=m;i++){
		int op;cin>>op;ll x,y,z;
		if(op==1){
			cin>>x>>y>>z;
			pathChange(x,y,z);
		}
		else if(op==2){
			cin>>x>>y;
			cout<<pathQuery(x,y)<<"\n";
		}
		else if(op==3){
			cin>>x>>z;
			subtreeAdd(x,z);
		}
		else if(op==4){
			cin>>x;
			cout<<subtreeQuery(x)<<"\n";
		}
	}
	
	return 0;
	
	
}
