#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int INF=1e9+7;

int n,k;
vector<int> colors(N);
vector<vector<int>> cows(52,vector<int>());
vector<vector<int>> g(52,vector<int>());

vector<bool> vis(N,false);

vector<int> bfs(int u){
    vector<int> res(N,INF);
    queue<int> q;
    q.push(u);
    vis[u]=true;
    while(!q.empty()){
        auto u=q.front();
        q.pop();

    }

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



}