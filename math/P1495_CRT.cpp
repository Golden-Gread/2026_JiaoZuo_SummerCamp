#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




ll exGCD(ll a, ll b, ll &x, ll &y) {//Ax+By=GCD(a,b)
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll gcd = exGCD(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int main(){
    int n;cin>>n;
    vector<ll> modN(n+1,0),modR(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>modN[i]>>modR[i];
    }
    __int128 M=1;
    for(int i=1;i<=n;i++){
        M*=modN[i];
    }

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll M_i=M/modN[i];
        ll t_i,y;
        exGCD(M_i,modN[i],t_i,y);
        t_i=(t_i%modN[i]+modN[i])%modN[i];
        ans=(ans+modR[i]*M_i%M*t_i%M)%M;
    }

    cout<<ans<<endl;
    return 0;
}