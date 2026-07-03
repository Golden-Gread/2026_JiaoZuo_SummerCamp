#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAXN=1e5+10;

vector<ll> ans(MAXN*4,0),maxl(MAXN*4,0);

ll query(ll p,ll l,ll r,long double k){
	if(maxl[p]<=k){
		return 0;
	}
	if(l==r){
		return maxl[p]>k;
	}
	ll mid=(l+r)>>1;
	if(maxl[p*2]<=k){
		return query(p*2+1,mid+1,r,k);
	}
	return query(p*2,l,mid,k)+ans[p]-ans[p*2];
}

void change(ll p,ll l,ll r,ll cp,long double new_k){
	if(l==cp and r==cp){
		ans[p]=1;
		maxl[p]=new_k;
		return;
	}
	ll mid=(l+r)>>1;
	
	if(cp<=mid) change(p*2,l,mid,cp,new_k);
	else change(p*2+1,mid+1,r,cp,new_k);
	
	maxl[p]=max(maxl[p*2],maxl[p*2+1]);
	ans[p]=ans[p*2]+query(p*2+1,mid+1,r,maxl[p*2]);
	
}

int main(){
	int n,m;scanf("%d %d\n",&n,&m);
	for(ll i=0;i<m;i++){
		ll cp,nh;scanf("%lld %lld\n",&cp,&nh);
		change(1,1,n,cp,(long double)nh/cp);
		printf("%lld\n",ans[1]);
	}
	return 0;
}
