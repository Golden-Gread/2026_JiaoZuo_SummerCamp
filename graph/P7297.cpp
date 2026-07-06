#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int INF=1e9+7;

int n,k;
vector<int> colors(N);
vector<vector<int>> cows(52,vector<int>());
vector<vector<int>> g(52,vector<int>());

vector<bool> vis(N,false);

vector<int> bfs(int u,int to){
    vector<int> res(N,INF);
    queue<int> q;
    q.push(u);
    vis[u]=true;
    res[u]=0; 
    while(!q.empty()){
        auto st=q.front();
        q.pop();
        if(st==to){
            break;
        }
        for(int color:g[st]){
            for(int v:cows[color]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    res[v]=min(res[v],res[st]+abs(colors[v]-colors[st]));
                }
            }
        }
    }

    return res;

}


int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>colors[i];
    }
    for(int i=1;i<=k;i++){
        string s;cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'){
                g[i].push_back(j+1);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cows[colors[i]].push_back(i);
    }

    int ans=bfs(1,n)[n];

    cout<<(ans==INF?-1:ans)<<endl;
    return 0;
}