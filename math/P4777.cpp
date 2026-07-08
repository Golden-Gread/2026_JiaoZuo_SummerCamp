#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;

ll exGCD(ll a,ll b,ll &x,ll &y) {//Ax+By=GCD(a,b)
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
    vector<ll> modN(n+1),modR(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",modN[i],modR[i]);
    }
}