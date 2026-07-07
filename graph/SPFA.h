#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=1e9+7;




bool SPFA(vector<vector<pii>> &graph,int start){
    int n=graph.size();  
    vector<int> dist(n+1,INF);
	
    vector<bool> in_queue(n+1,false);
	
    vector<int> count(n+1,0);
	
	
    dist[start]=0;

    queue<int> q;
    q.push(start);
    in_queue[start]=true;
    count[start]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        in_queue[u]=false;

        for(int i=0;i<int(graph[u].size());i++){
			auto p = graph[u][i];
            int v=p.first;
            int w=p.second;
            if(dist[u]!= INF and dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v]=true;
                    count[v]++;
                    if(count[v] > n){
                        return 0;
                    }
                }

            }
        }
    }
    return 1;
}