#include<bits/stdc++.h>
using namespace std;

const int modNum=1e9+7;
typedef long long ll;

int main(){
	int t,k;cin>>t>>k;
	vector<ll> dp(100004,0);
	dp[1]=1;
	for(int i=2;i<k;i++){
		dp[i]=dp[i-1];
	}
	dp[k]=2;
	
	for(int i=k;i<=100001;i++){
		dp[i]=(dp[i-1]+dp[i-k])%modNum;
		
	}
	
	
	for(int i=1;i<=t;i++){
		int l,r;cin>>l>>r;
		
		ll sum=0;
		for(int j=l;j<=r;j++){
			sum+=dp[j]%modNum;
		}
		
		cout<<sum<<endl;
		
	}
}
