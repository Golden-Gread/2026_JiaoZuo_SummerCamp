#include<bits/stdc++.h>
using namespace std;

void linear_sieve(int n,vector<int>& prime){
    vector<int> v(n+1,0);
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
