#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;
struct Node{int s,step;};


int SPFA(vii& a,int n,int m){
	vector<bool> vis(1010,0);
	queue<Node> q;
	int ss;
	q.push((Node){(1<<n)-1,0});
	vis[(1<<n)-1]=1;
	
	while(!q.empty()){
		Node u=q.front();
		q.pop();
		if(u.s==0){return u.step;}
		for(int i=1;i<=m;i++){
			ss=u.s;
			for(int j=1;j<=n;j++){
				if(a[i][j]==1 and (ss&(1<<j-1))){
					ss^=(1<<j-1);
				}
				else if(a[i][j]==-1 and !(ss&(1<<j-1))){
					ss|=(1<<j-1);
				}
			}
			if(!vis[ss]){
				q.push((Node){ss,u.step+1});
				vis[ss]=1;
			}
		}
	}
	
	return -1;
	
}




int main(){
	int n,m;cin>>n>>m;
	vii a(m+1,vector<int>(n+1,0));
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	printf("%d",SPFA(a,n,m));
	
	return 0;
}
