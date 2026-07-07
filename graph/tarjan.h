#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int nxt[N],dfn[N],low[N],dfs_cnt=0;
int scc[N],scc_cnt=0;
stack<int> stk;
bool instack[N]={false};
int tot=0;

struct Edge{
    int to,nxt;
} e[N];



void Tarjan(int u){
    dfn[u]=low[u]=++dfs_cnt;
    stk.push(u);
    instack[u]=true;
    for(int i=nxt[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[u]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }

    if(dfn[u]==low[u]){
        
    }
}