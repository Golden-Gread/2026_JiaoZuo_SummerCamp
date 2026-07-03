#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3*1e5+5;

struct Line{
    ll k,b;
    Line(ll _k=0,ll _b=0):k(_k),b(_b){}
    ll getY(ll x){
        return k*x+b;
    }
} lines[N];

vector<int> sta_time(N,0),end_time(N,0);
vector<int> opType(N,0),qs(N,0);

vector<int> tree[N*4];

bool cmp(int a_id,int b_id,int x){
    return (lines[a_id].getY(x)==lines[b_id].getY(x))?(a_id<b_id):lines[a_id].getY(x)>lines[b_id].getY(x);
}


void insert(int p,int l,int r)