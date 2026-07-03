#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const long long INF = 4e18;
const int X_L = -1e9, X_R = 1e9;

int n, op[N], k[N], b[N], lp[N], rp[N], rt[N << 2], tot;
int lc[N << 5], rc[N << 5], id[N << 5];
int pos[N];

// 计算直线在x处的值
inline long long val(int x, int lineId) {
    return 1LL * k[lineId] * x + b[lineId];
}

// 李超树插入（修正版）
inline void insert(int &u, int l, int r, int lineId) {
    if (!u) {
        u = ++tot;
        id[u] = lineId;
        return;
    }
    
    int mid = l + ((r - l) >> 1);
    long long curMid = val(mid, id[u]);
    long long newMid = val(mid, lineId);
    
    // 如果新直线在中点更优，交换
    if (newMid > curMid) {
        swap(id[u], lineId);
    }
    
    if (l == r) return;
    
    // 判断被替换的直线（现在在lineId中）是否在某个端点更优
    if (val(l, lineId) > val(l, id[u])) {
        insert(lc[u], l, mid, lineId);
    } else if (val(r, lineId) > val(r, id[u])) {
        insert(rc[u], mid + 1, r, lineId);
    }
    // 否则lineId完全无用，丢弃
}

// 查询（修正版）
inline long long query(int u, int l, int r, int x) {
    if (!u) return -INF;
    
    long long res = val(x, id[u]);
    if (l == r) return res;
    
    int mid = l + ((r - l) >> 1);
    if (x <= mid) {
        return max(res, query(lc[u], l, mid, x));
    } else {
        return max(res, query(rc[u], mid + 1, r, x));
    }
}

#define ls u << 1
#define rs u << 1 | 1

// 建立线段树，记录叶子节点位置
inline void build(int u, int l, int r) {
    if (l == r) {
        pos[l] = u;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

// 线段树分治：将直线lineId插入到时间区间[ql, qr]
inline void assign(int u, int l, int r, int ql, int qr, int lineId) {
    if (ql <= l && r <= qr) {
        insert(rt[u], X_L, X_R, lineId);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) assign(ls, l, mid, ql, qr, lineId);
    if (qr > mid) assign(rs, mid + 1, r, ql, qr, lineId);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    build(1, 1, n);
    
    // 读入操作
    for (int i = 1; i <= n; i++) {
        cin >> op[i];
        if (op[i] == 1) {
            cin >> k[i] >> b[i];
            lp[i] = i;
            rp[i] = n;  // 默认存活到结束
        } else if (op[i] == 2) {
            int idx;
            cin >> idx;
            rp[idx] = i - 1;  // 修正：在第i时刻被删除，所以存活到i-1
        } else {
            cin >> k[i];
        }
    }
    
    // 将所有直线插入线段树
    for (int i = 1; i <= n; i++) {
        if (op[i] == 1 && lp[i] <= rp[i]) {
            assign(1, 1, n, lp[i], rp[i], i);
        }
    }
    
    // 处理所有询问
    for (int i = 1; i <= n; i++) {
        if (op[i] == 3) {
            long long ans = -INF;
            // 从叶子到根，查询所有节点
            for (int u = pos[i]; u; u >>= 1) {
                ans = max(ans, query(rt[u], X_L, X_R, k[i]));
            }
            
            if (ans == -INF) {
                cout << "EMPTY SET\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
    
    return 0;
}