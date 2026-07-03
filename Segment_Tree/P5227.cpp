#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;//(dist,to)

//int dfs(vector<vector<pii>>& g,int node,int ans,vector<int>& visited){
//	if(visited[node]==1){
//        return ans;
//    }
//    visited[node]=1;
//    for(auto& [dist,to]:g[node]){
//        ans+=dfs(g,to,ans,visited);
//    }
//}
//
//int connectGraph(vector<vector<pii>>& g){
//	vector<int> visited(g.size(),0);
//    int ans=0;
//    dfs(g,0,ans,visited);
//    return ans;
//}

const int N=1e5+5;

struct Edge{int u,v;};
vector<Edge> edges(N);
struct Hist{int u,v,add_val;};
stack<Hist> history;
vector<int> tree[N*4];
int fa[N],size[N];
bool ans[N];

int find(int x){
    while(x!=fa[x]){
        x=fa[x];
    }
    return x;
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    
    if(size[fx]<size[fy]){
        swap(fx,fy);
    }
    history.push({fx,fy,size[fy]});
    fa[fy]=fx;
    size[fx]+=size[fy];
}

void rollback(int timepoint){
    while(!history.empty()&&history.size()>timepoint){
        int fx=history.top().u,fy=history.top().v;
        size[fy]=history.top().add_val;
        fa[fx]=fx;
        history.pop();
    }
}

void addEdge(int p,int l,int r,int )

int main(){
	
}
