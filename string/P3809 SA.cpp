#include<bits/stdc++.h>
using namespace std;

string s;
int n;
vector<int> sa,rk,height;

void build_sa(){
    if(n==0) return ;
    int alp=max(256,n);

    vector<int> cnt(alp,0);
    vector<int> rk_temp(alp),sa_temp(alp);
    
}



int main(){
    cin>>s;
    n=s.length();
    sa.resize(n);
    rk.resize(n);
    height.resize(n);
}