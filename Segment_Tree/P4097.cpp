#include<bits/stdc++.h>

using namespace std;

const int XMAX=39989;

struct Line{
	double k,b;int id;  // y=kx+b
	Line(double _k=0,double _b=0,double _id=0):k(_k),b(_b),id(_id){}
	
	double getY(int x){
		return k*x+b;
	}
};

int n,linecnt;
vector<Line> tree(XMAX*4);



int main(){
	
}
