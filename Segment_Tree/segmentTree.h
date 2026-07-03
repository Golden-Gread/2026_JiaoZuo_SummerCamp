#include <vector>

using namespace std;

class segmentTree{
private:
	vector<int> original_data;
    vector<int> tree;
    vector<int> lazy;
public:
    void buildTree(int l,int r,int p);
    void pushDown();
    void range_add(int l,int r,int v,int s,int t,int p);
    int getSum(int l,int r,int s,int t,int p);
};

inline void segmentTree::buildTree(int l,int r,int p){
    if(l==r){
        tree[p]=original_data[l];
        return ;
    }
    int mid=l+((r-l)>>1);
    buildTree(l,mid,p*2);
    buildTree(mid+1,r,p*2+1);
    tree[p]=tree[p*2]+tree[p*2+1];
}

inline void segmentTree::pushDown(){}

inline void segmentTree::range_add(int l,int r,int v,int s,int t,int p){

}