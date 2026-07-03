#include<bits/stdc++.h>

using namespace std;

const int XMAX=39989;
const int modX=39989;
const int modY=1e9;

struct Line{
	double k,b;int id;  // y=kx+b
	Line(double _k=0,double _b=0,double _id=0):k(_k),b(_b),id(_id){}
	double getY(int x){
		return k*x+b;
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


int build(int node,int l,int r){
	if()
}


int main(){
	
}
