#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    string str;
    int n;
    vector<int> sa, rank, tmp;
    SuffixArray(string s) {
        str = s;
        n = s.size();
        sa.resize(n);
        rank.resize(n);
        tmp.resize(n);
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = s[i];
        }
        for (int k = 1; k < n; k <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                int ri = (i + k < n) ? rank[i + k] : -1;
                int rj = (j + k < n) ? rank[j + k] : -1;
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
            }
            rank = tmp;
        }
    }
    int getRank(int i) {
        return rank[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }
    
    string rs = s;
    reverse(rs.begin(), rs.end());
    string combined = s + char('[') + rs;  // '[' 比 'Z' 大，用作分隔
    SuffixArray sa(combined);
    
    int l = 0, r = N - 1;
    string ans;
    ans.reserve(N);
    
    while (l <= r) {
        int rankL = sa.getRank(l);
        int rankR = sa.getRank(N + (N - 1 - r)); // rs 的起始位置在 combined 中
        if (rankL < rankR) {
            ans.push_back(s[l++]);
        } else {
            ans.push_back(s[r--]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if ((i + 1) % 80 == 0) cout << '\n';
    }
    if (N % 80 != 0) cout << '\n';
    
    return 0;
}