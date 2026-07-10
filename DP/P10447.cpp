#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;
const int INF=1e9+7;


void Hamilton(int n,vii& f,vii& a){
	f[1][0]=0;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(!((i>>j)&1)) continue;
			for(int k=0;k<n;k++){
				if(((i^(1<<j))>>k)&1){
					f[i][j]=min(f[i][j],f[i^(1<<j)][k]+a[k][j]);
				}
			}
		}
	}
	
}


int main(){
	int n;cin>>n;
	vector<vector<int>> f(1<<n,vector<int>(n+1,INF));
	vector<vector<int>> a(n+1,vector<int>(n+1,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	Hamilton(n,f,a);
	
	printf("%d",f[(1<<n)-1][n-1]);
	
	
	return 0;
}
