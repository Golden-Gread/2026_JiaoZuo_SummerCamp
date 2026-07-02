#include <vector>

using namespace std;

class segmentTree{
private:
	vector<int> original_data;
    vector<int> tree;
    vector<int> lazy;
public:
    void buildTree(int l,int r,int p);
    void range_add(int l,int r,int v,int s,int t,int p);
    int getSum(int l,int r,int s,int t,int p);
};

inline void segmentTree::buildTree(int l,int r,int p){

}