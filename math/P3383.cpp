#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n, q;
    scanf("%d %d\n",&n,&q);
    
    vector<int> prime;
    vector<int> v(n + 1, 0);
    

    prime.reserve(n / max(1, (int)log(n)));
    
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
    
    while (q--) {
        int x;
        scanf("%d",&x);
        printf("%d\n",prime[x-1]);
        
    }
    
    return 0;
}