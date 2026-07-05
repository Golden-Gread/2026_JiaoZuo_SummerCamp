#include <bits/stdc++.h>
using namespace std;
const int N=4e5+21;

int n,m,k,fa[N],height[N],top;

struct Edge{
	int u,v;
} e[N];

struct Node{
	int u,v,add;
};

stack<Node> histroy;
vector<int> tree[N];

int find(int x){
	while(x!=fa[x]){
		x=fa[x];
	}
	return x;
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	if(height[fx]<height[fy]){
		swap(fx,fy);
	}
	fa[fx]=fy;
	if(height[fx]==height[fy]){
		height[fy]++;
	}
}

void add_edge(int p,int l,int r,int L,int R,int x){
	if(L>r or r>L) return;
	if(L<=l && r>=R){
		tree[p].push_back(x);
		return;
	}
	int mid=(l+r)/2;
	add_edge(p*2,l,mid,L,R,x);
	add_edge(p*2+1,mid+1,r,L,R,x);
}

void dfs(int u,int l,int r){
	int ans=1;
	int timepoint=histroy.size();

	for(int i=0;i<tree[u].size();i++){
		auto it=e[tree[u].at(i)];
		int a=it.u,b=it.v;
		if(a==b){
			
		}
	}

}
