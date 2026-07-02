#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node{
	ll val;
	ll lazy;
	int rc;
	int lc;
	Node():val(0),lazy(0),rc(-1),lc(-1){}
};

vector<Node> tree;
int nodeNum=0;

int newNode(){
	tree.push_back(Node());
	return nodeNum++;
}

void pushDown(int p,int l,int r){
	if(tree[p].lazy==0 or l==r){
		return ;
	}
	
	int mid=(l+r)>>1;
	
	if(tree[p].lc==-1) tree[p].lc=newNode();
	if(tree[p].rc==-1) tree[p].rc=newNode();
	
	ll lazy_val=tree[p].lazy;
	int left=tree[p].lc,right=tree[p].rc;
	
	tree[left].lazy+=lazy_val,tree[right].lazy+=lazy_val;
	tree[left].val+=lazy_val*(mid-l+1),tree[right].val+=lazy_val*(r-mid);
	tree[p].lazy=0;
}

void range_adding(int l,int r,int v,int s,int t,int& p){
	
}


int main(){
	
}
