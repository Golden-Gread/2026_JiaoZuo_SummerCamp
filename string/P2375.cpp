#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int MOD=1e9+7;

vector<int> nxt(N),cnt(N);

void func(){
    char s[N];
    scanf("%s",s+1);
    int n=strlen(s+1);
    nxt[1]=0;
    cnt[1]=1;

    for(int i=2,j=0;i<=n;i++){
        while(j>0&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1]) j++;
        nxt[i]=j;
        cnt[i]=cnt[j]+1;
    }

    long long ans=1;
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1]) j++;
        while(j*2>i) j=nxt[j];
        ans=ans*(cnt[j]+1)%MOD;
    }

    printf("%lld\n",ans%MOD);

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) func();
    return 0;
}