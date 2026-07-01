#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int lowbit(int x){
	return x & -x;
}

void add(int index,int value,vector<ll>& arr){
	while(index<=arr.size()-1){
		arr[index]+=value;
		index+=lowbit(index);
	}
}

ll cheak(int x,vector<ll>& arr){
	ll ans=0;
	while(x>0){
		ans+=arr[x];
		x-=lowbit(x);
	}
	return ans;
}

ll getSum(int sta,int ending,vector<ll>& arr){
	ll ans1=cheak(sta-1,arr),ans2=cheak(ending,arr);
	return ans2-ans1;
	
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<ll> data(n+1,0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		add(i,x,data);
		
	}
	for(int i=0;i<m;i++){
		int code,x,y;
		cin>>code>>x>>y;
		if(code==1){
			add(x,y,data);
		}
		else{
			cout<<getSum(x,y,data)<<endl;
		}
	}
	
	return 0;
	
}
