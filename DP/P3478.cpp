#include <bits/stdc++.h>
using namespace std;

int bfs_count(vector<vector<int>>& tree,int now){
	queue<int> q;
	q.push(now);
	int ans=0;
	while(!q.empty()){
		auto it=q.front();q.pop();
		for(int to:tree[it]){
			q.push(to);
			ans++;
		}
	}
	return ans;
}

int main(){
	return 0;
}
