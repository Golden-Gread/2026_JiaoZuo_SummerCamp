#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> pii;
vector<vector<pii>> que(N);//待询问的数组
int trie[N][26],depth[N],tot=0,parent[N],ancestor[N];//字典树
bool vis[N];
int ans[N];

int find(int x){
    return x==parent[x]?x:parent[x]=find(parent[x]);
}


void tarjan(int node,vector<vector<int>> &g){
    parent[node]=node;
    ancestor[node]=node;

    for(int v:g[node]){
        depth[v]=depth[node]+1;
        tarjan(v,g);
        parent[v]=node;
        ancestor[find(node)]=node;
    }

    vis[node]=true;
    for(auto it:que[node]){
        int v=it.first,id=it.second;
        if(vis[v]){
            int lca=ancestor[find(v)];
            ans[id]=depth[lca];
        }
    }
}


int main(){
    char s[N];scanf("%s",s+1);
    int len=strlen(s+1);
    vector<int> nxt(len+1,0);

    for(int i=2,j=0;i<=len;i++){
        while(j>=0&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1]) j++;
        nxt[i]=j;
    }
        
    vector<vector<int>> g(len+1);

    for(int i=1;i<=len;i++){
        int fa=nxt[i];
        g[fa].push_back(i);
    }

    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int p,q;scanf("%d %d",&p,&q);
        que[p].push_back({q,i});
        que[q].push_back({p,i});
    }

    tarjan(1,g);

    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }

    return 0;

}

