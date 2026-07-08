#include<bits/stdc++.h>
using namespace std;

void linear_sieve(int n,vector<int>& prime){
    vector<int> v(1e6+2,0);
    prime.reserve(n/max(1,(int)log(n)));
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            v[i] = i;
            prime.push_back(i);
        }
        for (int p : prime) {
            long long t = 1LL * i * p;
            if (t > n) break;
            v[t] = p;
            if (p == v[i]) break;
        }
    }
}



int main(){
        int n;cin>>n;
        vector<int> prime;
        linear_sieve(n,prime);
        for(int i=0;i<prime.size();i++){
            int sum=0;
            for(int j=1;pow(prime[i],j)<=n;j++){
                sum+=n/pow(prime[i],j);
            }
            printf("%d %d\n",prime[i],sum);
        }
    
    return 0;
}