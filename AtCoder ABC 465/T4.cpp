#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        ll x,y,k;cin>>x>>y>>k;
        int cnt=0;
        while(x!=y){
            if(x>y){
                x/=k;
            }
            else{
                for(ll j=x*k;j<(x+1)*k;j++){
					if((y/k)*k!=x*k){
						x=y;
					}
				}
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
