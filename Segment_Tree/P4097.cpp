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
};

bool cmp(Line a,Line b,int x){
	int y1=a.getY(x),y2=b.getY(x);
	return (fabs(y1-y2)<eps)?a.id<b.id:y1>y2;
}

struct Node{
	int l,r,id;  // [l,r]
	Line line;
	int lc,rc;
	Node(int _l=0,int _r=0,int _id=0):l(_l),r(_r),id(_id),lc(-1),rc(-1){}
};


int n,linecnt;

vector<Node> tree(XMAX*4);
vector<Line> lines(XMAX*4);


void add_line(int node,int l,int r,int L,int R,int p){
	if(L<=l&&r<=R){
		int mid=(l+r)>>1;
		int &v=tree[node].id;
		if(v==0){
			v=p;
			return;
		}
		if(cmp(lines[p],lines[v],mid)){
			swap(lines[p],lines[v]);
		}
		if(l==r) return;
		if(cmp(lines[p],lines[v],l)) add_line(tree[node].lc,l,mid,L,R,p);
		else if(cmp(lines[p],lines[v],r)) add_line(tree[node].rc,mid+1,r,L,R,p);
		return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid) add_line(tree[node].lc,l,mid,L,R,p);
	if(R>mid) add_line(tree[node].rc,mid+1,r,L,R,p);
}




int main(){
	
}
