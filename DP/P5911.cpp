#include <bits/stdc++.h>
using namespace std;


int main(){
	int W,n;cin>>W>>n;
	vector<int> weight(n+1,0),time(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>time[i]>>weight[i];
	}
	vector<int> Weight((1<<n)+1,0),T((1<<n)+1,0);
	
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				T[i]=max(T[i],time[j]);
				Weight[i]+=weight[j];
			}
		}
	}
	
	
	
	vector<int> dp(1<<n,1000003);
	dp[0]=0;
	
	for(int i=1;i<1<<n;i++){
		for(int j=i;;j=i&(j-1)){
			if(Weight[i^j]<=W) dp[i]=min(dp[i],dp[j]+T[i^j]);
			if(!j) break;
		}
	}
	
	cout<<dp[(1<<n)-1];
	
	return 0;
}
