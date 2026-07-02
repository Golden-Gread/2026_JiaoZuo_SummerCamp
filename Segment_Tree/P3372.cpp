#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> Data(400005,0),tree(400005,0),temp(400005,0);




void buildTree(ll start,ll ending,ll treeCode){
	if(start==ending){
		tree[treeCode]=Data[start];
		return ;
	}
	ll mid=start+((ending-start) >> 1);
	buildTree(start,mid,treeCode*2);
	buildTree(mid+1,ending,treeCode*2+1);
	tree[treeCode]=tree[treeCode*2]+tree[treeCode*2+1];
}

void range_adding(ll change_s,ll change_t,ll value,ll cheak_s,ll cheak_t,ll treeCode){
	if(change_s<=cheak_s and cheak_t<=change_t){
		tree[treeCode]+=(cheak_t-cheak_s+1)*value;
		temp[treeCode]+=value;
		return;
	}
	ll mid=cheak_s+((cheak_t-cheak_s) >> 1);
	if(temp[treeCode]!=0){
		temp[treeCode*2]+=temp[treeCode],temp[treeCode*2+1]+=temp[treeCode];
		tree[treeCode*2]+=temp[treeCode]*(mid-cheak_s+1),tree[treeCode*2+1]+=temp[treeCode]*(cheak_t-mid);
		temp[treeCode]=0;
	}
	if(change_s<=mid) range_adding(change_s,change_t,value,cheak_s,mid,treeCode*2);
	if(change_t>mid) range_adding(change_s,change_t,value,mid+1,cheak_t,treeCode*2+1);
	tree[treeCode]=tree[treeCode*2]+tree[treeCode*2+1];
}

ll getSum(ll change_s,ll change_t,ll cheak_s,ll cheak_t,ll treeCode){
	if(change_s>cheak_t or change_t<cheak_s){
		return 0;
	}
	if(change_s <= cheak_s && cheak_t <= change_t){
		return tree[treeCode];
	}
	
	ll mid=cheak_s+((cheak_t-cheak_s) >> 1);
	if(temp[treeCode]!=0){
		temp[treeCode*2]+=temp[treeCode],temp[treeCode*2+1]+=temp[treeCode];
		tree[treeCode*2]+=temp[treeCode]*(mid-cheak_s+1),tree[treeCode*2+1]+=temp[treeCode]*(cheak_t-mid);
		temp[treeCode]=0;
	}
	ll sum=0;
	if(change_s<=mid) sum+=getSum(change_s,change_t,cheak_s,mid,treeCode*2);
	if(change_t>mid) sum+=getSum(change_s,change_t,mid+1,cheak_t,treeCode*2+1);
	return sum;
}

int main(){
	ll n,m;cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>Data[i];
	}
	
	buildTree(1,n,1);
	
	
	for(ll i=0;i<m;i++){
		ll code;cin>>code;
		if(code==1){
			ll x,y,k;cin>>x>>y>>k;
			range_adding(x,y,k,1,n,1);
		}
		else if(code==2){
			ll x,y;cin>>x>>y;
			cout<<getSum(x,y,1,n,1)<<endl;
		}
	}
	return 0;
	
}
