#ifndef TREE_ARR
#define TREE_ARR


#include<vector>


class HxTree {
    private:
        std::vector<int> tree;
    public:
        HxTree(): tree() {}
        int lowbit(int x){
            return x&(-x);
        }
        void addNode(int index,int value);
        void loadData(std::vector<int> data);
        int gs(int index);
        int getSum(std::pair<int,int> range);
};

inline void HxTree::addNode(int index,int value) {
    while(index<=tree.size()-1){
        tree[index]+=value;
        index+=lowbit(index);
    }
}

inline void HxTree::loadData(std::vector<int> data){
    for(int i=1;i<=data.size();i++){
        addNode(i,data[i-1]);
    }
}

inline int HxTree::gs(int index){
    int sum=0;
    while(index>0){
        sum+=tree[index];
        index-=lowbit(index);
    }
    return sum;
}

inline int HxTree::getSum(std::pair<int,int> range){
    int sum=0;
    int lsum=gs(range.first-1);
    int rsum=gs(range.second);
    sum=rsum-lsum;
    return sum;
}

#endif