#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int INF=1e9+7;




bool SPFA(vector<vector<pii>> &graph,vector<int> &dist,int start){
    int n=graph.size();  
    
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
                    if(count[v] > n) return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    int n,x,y,s;
    cin>>n>>x>>y>>s;
    vector<vector<pii>> graph(n+1,vector<pii>());
    for(int i=0;i<x;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    for(int i=0;i<y;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    vector<int> dist(n+1,INF);
    if(SPFA(graph,dist,s)){
        for(int i=1;i<=n;i++){
            if(dist[i]!=INF){
                cout<<dist[i]<<endl;
            }
            else{
                cout<<"NO PATH"<<endl;
            }
        }
    }

}