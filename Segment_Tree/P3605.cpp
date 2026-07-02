#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N=1e5+10;

ll n;
vector<ll> p(N,0),b(N,0),ans(N,0);
vector<vector<ll>> g(N);


struct HxTree{
	
	vector<ll> tree;
	
	ll lowbit(ll x){
		return x&-x;
	}
	
	void addNode(ll index,ll val){
		for(;index<=n;index+=lowbit(index)){
			tree[index]+=val;
		}
	}
	
	ll quety(int ind){
		ll sum=0;
		for(;ind>0;ind-=lowbit(ind)){
			sum+=tree[ind];
		}
		return sum;
	}
	
	ll getSum(ll s,ll t){
		if(s>t) return 0;
		return quety(t)-quety(s-1);
	}
};

HxTree ht;



void dfs(ll node){
	ll before=ht.getSum(p[node]+1,n);
	for(auto i:g[node]) dfs(i);
	ll after=ht.getSum(p[node]+1,n);
	ans[node]=after-before;
	ht.addNode(p[node],1);
}

int main(){
	cin>>n;
	ht.tree.resize(N,0);
	for(ll i=1;i<=n;i++){
		cin>>b[i];p[i]=b[i];
	}
	sort(b.begin()+1,b.begin()+n+1);
	for(ll i=1;i<=n;i++){
		p[i]=lower_bound(b.begin()+1,b.begin()+n+1,p[i])-b.begin();
	}
	for(ll i=2;i<=n;i++){
		ll father;cin>>father;
		g[father].push_back(i);
	}
	dfs(1);
	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
