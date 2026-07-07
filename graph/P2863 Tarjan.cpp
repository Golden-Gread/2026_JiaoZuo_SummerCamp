#include <bits/stdc++.h>
using namespace std;
const int N=1e5+4;

struct Edge{
    int to,nxt;
} e[N];
int dfn[N],low[N],dfn_cnt=0;
bool in_stack[N]={0};
stack<int> S;
int SCC[N],SCC_cnt=0;
int SCC_size[N]={0};
int nxt[N],tot=0;

void add_edge(int u,int v){
    e[++tot]=(Edge){v,nxt[u]};
    nxt[u]=tot;
}



void Tarjan(int u){
    low[u]=dfn[u]=++dfn_cnt;
    S.push(u);
    in_stack[u]=true;
    for(int i=nxt[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(in_stack[v]){
            low[u]=min(low[u],dfn[v]);  
        }
    }

    if(dfn[u]==low[u]){
        ++SCC_cnt;
        int x;  

        do {
            x = S.top();
            S.pop();
            SCC[x] = SCC_cnt;
            SCC_size[SCC_cnt]++;
            in_stack[x] = false;
        } while (x != u);

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
    }

    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            Tarjan(i);
        }
    }

    int ans=0;
    for(int i=1;i<=SCC_cnt;i++){
        if(SCC_size[i]>1){
            ans++;
        }
    }

    cout<<ans;
    return 0;
}