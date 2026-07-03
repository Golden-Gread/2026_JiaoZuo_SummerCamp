#include<bits/stdc++.h>

using namespace std;

const int M=2e5+4;

int n=0;

struct Edge{
	int u,v;
	Edge():u(-1),v(-1){}
} e[M];

//rollback DSU

vector<int> fa(M*2,0),size(M*2,0);
struct hist{int u,v,add_sz;};
stack<hist> history={};

int find(int x){
	while(fa[x]!=x){
		
		x=fa[x];
	}
	return x;
}

bool unite(int u,int v){
	int fa_u=find(u),fa_v=find(v);
	if(fa_u==fa_v){ history.push({-1, -1, -1});return false;}
	
	if(size[fa_u]>size[fa_v])
		swap(fa_u,fa_v);
	
	history.push((hist){fa_u,fa_v,size[fa_u]});//saving history of DSU
	
	fa[fa_u]=fa_v;
	size[fa_v]+=size[fa_u];
	return true;
}

void rollback(){
	if(history.empty()) return;
	auto it=history.top();history.pop();
	int u=it.u,v=it.v,ch_val=it.add_sz;
	if(u==-1) return;
	fa[u]=u;
	size[v]-=ch_val;
}

void rollback_to_point(int x){
	while(history.size()>x){
		rollback();
	}
}


// Time Segment Tree
vector<int> tree[M*4];

void adding_edge(int node,int nd_l,int nd_r,int ed_l,int ed_r,int edge){
	if(ed_l<=nd_l and nd_r<=ed_r){  //completely covered
		tree[node].push_back(edge);
		return ;
	}
	int mid=(nd_l+nd_r)>>1;
	if(ed_l<=mid) adding_edge(node*2,nd_l,mid,ed_l,ed_r,edge);
	if(ed_r>mid) adding_edge(node*2+1,mid+1,nd_r,ed_l,ed_r,edge);
}

void dfs(int node,int l,int r,bool& is_right){
	if(l>r) return ;
	
	//if(!is_right) {
	//	if(l == r) {
	//		cout << "No\n";
	//	} else {
	//		int mid = (l + r) >> 1;
	//		dfs(node * 2, l, mid, is_right);
	//		dfs(node * 2 + 1, mid + 1, r, is_right);
	//	}
	//	return;
	//}
	
	int timepoint=history.size();
	
	for(int edge:tree[node]){
		int u=e[edge].u,v=e[edge].v;
		
		bool res1=unite(u,v);
		//bool res2=unite(v,u+n);
		if(!res1){
			is_right=0;
			break;
		}
	}
	
	if(l==r){
		printf("%s",((is_right)?"Yes":"No"));
	}
	else{
		int mid=(l+r)>>1;
		dfs(node*2,l,mid,is_right);
		dfs(node*2+1,mid+1,r,is_right);
	}
	
	rollback_to_point(timepoint);
}

int main(){
	int m,k;scanf("%d %d %d",&n,&m,&k);
	
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
		size[i]=1;
	}
	
	for(int i=1;i<=m;i++){
		int l,r;scanf("%d %d %d %d",&e[i].u,&e[i].v,&l,&r);
		if(l<r){
			adding_edge(1,1,k,l+1,r,i);
		}
	}
	bool b=1;
	dfs(1,1,k,b);
	
	return 0;
}
