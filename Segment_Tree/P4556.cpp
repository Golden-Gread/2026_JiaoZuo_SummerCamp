#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+4;
int n,m;


struct data{
	int u,cnt;
	data():u(0),cnt(0){}
	data(int a,int b):u(a),cnt(b){}
	
	friend bool operator <(data d1,data d2){
		return (d1.cnt==d2.cnt)?d1.u>d2.u:d1.cnt<d2.cnt;
	}
	
	friend data operator +(data a,data b){
		return data(a.u,a.cnt+b.cnt);
	}
	
};

struct linelist{
	int son[N][2];
	
};




