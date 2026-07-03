#include<bits/stdc++.h>

using namespace std;

const int XMAX=39989;
const int modX=39989;
const int modY=1e9;
const double eps=1e-9;

struct Line{
	double k,b;int id;  // y=kx+b
	Line(double _k=0,double _b=0,double _id=0):k(_k),b(_b),id(_id){}
	double getY(int x){
		return k*x+b;
	}

	friend bool operator <(Line a,Line b){
		if(fabs(a.k-b.k)<eps)
			return a.b<b.b;
		return a.k<b.k;
	}
};

struct Node{
	int l,r,id;  // [l,r]
	Line line;
	int lc,rc;
	Node(int _l=0,int _r=0,int _id=0):l(_l),r(_r),id(_id),lc(-1),rc(-1){}
};


int n,linecnt;

vector<Node> tree(XMAX*4);
vector<Line> lines(XMAX*4);


void build(int node,int l,int r,int L,int R,int p){
	if(L<=l&&r<=R){
		
	}
}


int main(){
	
}
