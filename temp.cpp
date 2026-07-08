#include<bits/stdc++.h>
#define int __int128
using namespace std;
int a,b,x=1,y=0,sa=1,sb;
void exgcd(int gay,int lala,int &x,int &y){
    if(lala==0){
        x=1,y=0;
        return ;
    }
    exgcd(lala,gay%lala,y,x);
    y-=gay/lala*x;
}
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
long long read(){
    long long  x;
    cin>>x;
    return x;
    // int x=0;
    // char c=gc;
    // while(isdigit(c)) x=x*10+c-'0',c=gc;
    // return x;
}
void out(int x){
    if(x==0) return ;
    out(x/10);
    signed xx=x%10;
    cout<<xx;
}
signed main(){
	// freopen("D:/P4777_15.in","r",stdin);
    int n=read();
    for(int i=1;i<=n;i++){
        a=read(),b=read();
        exgcd(sa,a,x,y);
        int Gcd=gcd(sa,a);
        assert(Gcd!=0);
        x*=(sb-b)/Gcd;
        sb-=sa*x;
        sa*=a/Gcd;
        assert(sa!=0);
        sb=(sb%sa+sa)%sa;
    }
    out(sb);
    return 0;
}
