#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; //1e6*2
int dfn[N],low[N],cnt=0,nxt[N];//cnt->dfs number
int scc[N],scc_cnt=0;
int scc_size[N]={0};//Scc size
bool in_stack[N]={false};
stack<int> st;
int tot=0;


struct Edge{
    int to,nxt;
} e[N];

void addEdge(int u,int v){
    e[++tot]=(Edge){v,nxt[u]};
    nxt[u]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    st.push(u);
    in_stack[u]=true;
    for(int i=nxt[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(in_stack[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }

    if(dfn[u]==low[u]){
        int cur;
        ++tot;
        do{
            cur=st.top();
            st.pop();
            in_stack[cur]=false;
            scc[cur]=scc_cnt;
            ++scc_size[scc_cnt];
        }while(cur!=u);   
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        addEdge(b ? a + n : a, d ? c : c + n);
        addEdge(d ? c + n : c,b ? a : a + n);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(scc[i]==scc[i+n]){
            printf("%s","IMPOSSIBLE\n");
            return 0;
        }
    }

    printf("%s","POSSIBLE\n");
    for(int i=1;i<=n;i++){
        if(scc[i]<scc[i+n]){
            cout<<1<<' ';
        }
        else{
            cout<<0<<" ";
        }
    }

    return 0;

}