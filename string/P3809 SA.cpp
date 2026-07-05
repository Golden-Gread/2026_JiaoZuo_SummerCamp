#include<bits/stdc++.h>
using namespace std;

string s;
int n;
vector<int> sa,rk,height;

void rsort(vector<int> &cnt,int alp,vector<int> &sa_temp,vector<int> &rk_temp){
    for(int i=0;i<alp;i++) cnt[rk[i]]++;
    for(int i=1;i<n;i++) cnt[rk[rk_temp[i]]]++; 
    for(int i=1;i<alp;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--) sa_temp[--cnt[rk[rk_temp[i]]]]=rk_temp[i];    
}

void build_sa(){
    if(n==0) return ;
    int alp=max(256,n);

    vector<int> cnt(alp,0);
    vector<int> rk_temp(n),sa_temp(n);
    
    for(int i=0;i<n;i++) rk[i]=s[i],rk_temp[i]=i;
    rsort(cnt,alp,sa_temp,rk_temp);
    for(int k=1;k<n;k*=2){
        int p=0;
        for(int i=n-k+1;i<=n;i++) rk_temp[++p]=i;
        for(int i=1;i<=n;i++){
            if(sa[i]>k) rk_temp[++p]=sa[i]-k;
        }
        rsort(cnt,alp,sa_temp,rk_temp);
        rk.swap(rk_temp);
        rk[sa[1]]=p=1;
        for(int i=2;i<=n;i++){
            bool isSame=rk[sa[i]]==rk[sa[i-1]] && (sa[i]+k<=n?rk[sa[i]+k]:0);
            rk[sa[i]]= isSame?p:++p;
        }
    }
}



int main(){
    cin>>s;
    n=s.length();
    sa.resize(n+1);
    rk.resize(n+1);
    height.resize(n+1);

    build_sa();

    for (int i = 1; i <= n; ++i) {
        printf("%d ", sa[i]);
    }
    return 0;
}