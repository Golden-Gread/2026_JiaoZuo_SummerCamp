#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct AC{
    int trie[N][26];
    int fail[N];
    int cnt[N];
    int idx;

    void init(){
        memset(trie,0,sizeof(trie));
        memset(fail,0,sizeof(fail));
        memset(cnt,0,sizeof(cnt));
        idx=0;
    }

    void insert(string s){
        int p=0;
        for(auto ch:s){
            int c=ch-'a';
            if(!trie[p][c]) trie[p][c]=++idx;
            p=trie[p][c];
        }
        cnt[p]++;
    }

    void build(){
        queue<int> q;
        for(int i=0;i<26;i++){
            if(trie[0][i]){
                q.push(trie[0][i]);
                fail[trie[0][i]]=0;
            }
        }

        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;i++){
                int &v=trie[u][i];
                if(v){
                    fail[v]=trie[fail[u]][i];
                    q.push(v);
                }else{
                    v=trie[fail[u]][i];
                }

            }
        }

    }

    int query(string s){
        int u=0,res=0;
        for(auto ch:s){
            int c=ch-'a';
            u=trie[u][c];
            int temp=u;
            while(temp>0 and cnt[temp]!=-1){
                res+=cnt[temp];
                cnt[temp]=-1;
                temp=fail[temp];
            }
        }
        return res;
    }
};

AC ac;

int main(){
    int n;
    ac.init();
    cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        ac.insert(s);
    }
    ac.build();
    string t;cin>>t;
    cout<<ac.query(t)<<endl;
    return 0;

}