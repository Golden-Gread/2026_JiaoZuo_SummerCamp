#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
string s;
int n, m;
int sa[MAXN], rk[MAXN], tp[MAXN], tax[MAXN];


void rsort() {
    for (int i = 0; i <= m; ++i) tax[i] = 0;
    for (int i = 1; i <= n; ++i) tax[rk[tp[i]]]++;
    for (int i = 1; i <= m; ++i) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; --i) sa[tax[rk[tp[i]]]--] = tp[i];
}


void build_sa() {
    m = 130; 


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
    s.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    } 

    string rs=s.substr(1);
    reverse(rs.begin(),rs.end());
    
    s=s+"["+rs;
    int temp_n=n;
    n=2*n+1;

    build_sa();

    n=temp_n; 

    int l = 1, r = n;
    string ans;
    ans.reserve(n+1);
    


    while (l <= r) {

        int rankL = rk[l];
        
        int posR = 2 * n - r + 2;  
        int rankR = rk[posR];
        
        if (rankL < rankR) {
            ans.push_back(s[l++]);
        } else {
            ans.push_back(s[r--]);
        }
    }
    
    // 输出，每80个字符换行
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        //if ((i + 1) % 80 == 0) cout << '\n';
    }
    //if (MAXN % 80 != 0) cout << '\n';
    
    return 0;
}
