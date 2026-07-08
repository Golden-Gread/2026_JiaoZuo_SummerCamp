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

    i128 gcd = exGCD(b, a % b, x, y);
    i128 temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int main(){
    freopen("D:/P4777_15.in","r",stdin);


    int n;scanf("%d",&n);
    vector<ll> modN(n+1),modR(n+1);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&modN[i],&modR[i]);
    }

    ll M=modN[1];
    ll ans=modR[1];
    bool flag=true;
    for(int i=2;i<=n;i++){
        ll x,y;
        i128 gcd=exGCD(M,modN[i],x,y);
        i128 c=((modR[i]-ans)%modN[i]+modN[i])%modN[i];
    
        if(c%gcd!=0){
            flag=false;
            break;
        }
    
        ll mod=modN[i]/gcd;
        i128 temp=(i128)(x*c/gcd);
        x=temp%mod;

        ans=ans+x*M;
        M=M/gcd*modN[i];
        ans=(ans%M+M)%M;
    }

    if(flag){
        printf("%lld\n",ans);
    }else{
        printf("-1\n");
    }

    return 0;


}