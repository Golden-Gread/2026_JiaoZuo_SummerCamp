#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,q;cin>>n>>q;
    
    int v[10000000+1]={0};
    vector<int> prime;
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            prime.push_back(i);
            v[i]=i;
            //phi[i]=i-1;
        }
        for(auto p:prime){
            if(1LL*i*p>n or p>v[i]){
                break;
            }
            v[i*p]=p;
        }
    }

    
    
    for(int i=0;i<q;i++){
        int x;scanf("%d",&x);
        printf("%d\n",prime[x-1]);
    }

    return 0;
}