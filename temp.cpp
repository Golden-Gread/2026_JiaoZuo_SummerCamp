#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;
const int MAXX = 40000;
const double EPS = 1e-9;

struct Line {
    double k, b;
    Line(double _k = 0, double _b = -1e18) : k(_k), b(_b) {}
};

double calc(const Line& l, int x) {
    return l.k * x + l.b;
}

Line lines[MAXN];
int seg[MAXN << 2];

bool better(int a, int b, int x) {
    if (a == 0) return false;
    if (b == 0) return true;
    double ya = calc(lines[a], x);
    double yb = calc(lines[b], x);
    if (fabs(ya - yb) > EPS) return ya > yb;
    return a < b;
}

void insert(int rt, int l, int r, int L, int R, int u) {
    if (L <= l && r <= R) {
        int mid = (l + r) >> 1;
        int &v = seg[rt];
        if (v == 0) {
            v = u;
            return;
        }
        if (better(u, v, mid)) swap(u, v);
        if (l == r) return;
        if (better(u, v, l)) insert(rt << 1, l, mid, L, R, u);
        else if (better(u, v, r)) insert(rt << 1 | 1, mid + 1, r, L, R, u);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) insert(rt << 1, l, mid, L, R, u);
    if (R > mid) insert(rt << 1 | 1, mid + 1, r, L, R, u);
}

int query(int rt, int l, int r, int x) {
    int res = seg[rt];
    if (l == r) return res;
    int mid = (l + r) >> 1;
    int child;
    if (x <= mid) child = query(rt << 1, l, mid, x);
    else child = query(rt << 1 | 1, mid + 1, r, x);
    if (better(child, res, x)) res = child;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    
    int lastans = 0, cnt = 0;
    lines[0] = Line(0, -1e18);
    
    while (q--) {
        int op;
        cin >> op;
        
        if (op == 0) {
            int x;
            cin >> x;
            x = (x + lastans - 1) % MAXX + 1;
            lastans = query(1, 1, MAXX, x);
            cout << lastans << '\n';
        } else {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            
            x0 = (x0 + lastans - 1) % MAXX + 1;
            x1 = (x1 + lastans - 1) % MAXX + 1;
            y0 = (y0 + lastans - 1) % 1000000000 + 1;
            y1 = (y1 + lastans - 1) % 1000000000 + 1;
            
            if (x0 > x1) {
                swap(x0, x1);
                swap(y0, y1);
            }
            
            cnt++;
            double k, b;
            if (x0 == x1) {
                k = 0;
                b = max(y0, y1);
            } else {
                k = 1.0 * (y1 - y0) / (x1 - x0);
                b = y0 - k * x0;
            }
            lines[cnt] = Line(k, b);
            insert(1, 1, MAXX, x0, x1, cnt);
        }
    }
    return 0;
}