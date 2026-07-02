#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node{
	ll val;
	ll lazy;
	int rc;
	int lc;
	Node():val(0),lazy(0),rc(-1),lc(-1){}
};

vector<Node> tree;
int nodeNum=0;

int newNode(){
	tree.push_back(Node());
	return nodeNum++;
}

void pushDown(int p,int l,int r){
	if(tree[p].lazy==0 or l==r){
		return ;
	}
	
	int mid=(l+r)>>1;
	
	if(tree[p].lc==-1) tree[p].lc=newNode();
	if(tree[p].rc==-1)tree[p].rc=newNode();
	
	ll lazy_val=tree[p].lazy;
	int left=tree[p].lc,right=tree[p].rc;
	
	tree[left].lazy+=lazy_val,tree[right].lazy+=lazy_val;
	tree[left].val+=lazy_val*(mid-l+1),tree[right].val+=lazy_val*(r-mid);
	tree[p].lazy=0;
}

void range_adding(int l,int r,ll v,int s,int t,int& p){
	if(p==-1){
		p=newNode();
	}
	if(l<=s and t<=r){
		tree[p].val+=(t-s+1)*v;
		tree[p].lazy+=v;
		return ;
	}
	ll mid=s+((t-s)>>1);
	pushDown(p,s,t);
	if(l<=mid) range_adding(l,r,v,s,mid,tree[p].lc);
	if(r>mid) range_adding(l,r,v,mid+1,t,tree[p].rc);
	//tree[p].val=tree[tree[p].lc].val+tree[tree[p].rc].val;
	tree[p].val = 0;
	if (tree[p].lc != -1) tree[p].val += tree[tree[p].lc].val;
	if (tree[p].rc != -1) tree[p].val += tree[tree[p].rc].val;
}


ll getSum(int l,int r,int s,int t,int& p){
	if(r<s or l>t or p==-1) return 0;
	if(l<=s and t<=r) return tree[p].val;
	ll mid=s+((t-s)>>1);
	pushDown(p,s,t);
	ll sum=0;
	if(l<=mid) sum+=getSum(l,r,s,mid,tree[p].lc);
	if(r>mid) sum+=getSum(l,r,mid+1,t,tree[p].rc);
	return sum;
}

int main(){
	int n,m;cin>>n>>m;
	
	int root=newNode();
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		range_adding(i,i,x,1,n,root);
	}
	for(int i=0;i<m;i++){
		int code;cin>>code;
		if(code==1){
			ll x,y,k;cin>>x>>y>>k;
			range_adding(x,y,k,1,n,root);
		}
		else{
			int x,y;cin>>x>>y;
			cout<<getSum(x,y,1,n,root)<<endl;
		}
	}
	
	return 0;
	
}
