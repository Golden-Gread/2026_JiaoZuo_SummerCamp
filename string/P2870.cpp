#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
char s[MAXN];
int n, m;
int sa[MAXN], rk[MAXN], tp[MAXN], tax[MAXN];


void rsort() {
    for (int i = 0; i <= m; ++i) tax[i] = 0;
    for (int i = 1; i <= n; ++i) tax[rk[tp[i]]]++;
    for (int i = 1; i <= m; ++i) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; --i) sa[tax[rk[tp[i]]]--] = tp[i];
}


void build_sa() {
    m = 122; 


    for (int i = 1; i <= n; ++i) rk[i] = s[i], tp[i] = i;
    rsort();


    for (int k = 1, p = 0; p < n; k <<= 1, m = p) {
        p = 0;

        for (int i = n - k + 1; i <= n; ++i) tp[++p] = i;

        for (int i = 1; i <= n; ++i)
            if (sa[i] > k) tp[++p] = sa[i] - k;

        rsort(); 


        swap(rk, tp);
        rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; ++i) {
         
            bool same = (tp[sa[i]] == tp[sa[i - 1]] &&
                         (sa[i] + k <= n ? tp[sa[i] + k] : 0) == (sa[i - 1] + k <= n ? tp[sa[i - 1] + k] : 0));
            rk[sa[i]] = same ? p : ++p;
        }
    }
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    } 


    build_sa();

    for (int i = 1; i <= n; ++i) {
        printf("%d ", sa[i]);
    }
    return 0;
}