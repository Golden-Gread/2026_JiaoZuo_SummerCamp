#include<vector>
#include<stack>

struct Node{
    int u,v,add_val;
};

class rbDSU{
    private:
        std::vector<int> father;
        std::stack<Node> history;
    public:
        
        int find(int x);
        void unite(int x,int y);
        void rollback();
        int get_timepoint();
        void rollback_to(int tp);
};

inline int rbDSU::find(int x){
    if(father[x]==x){
        return x;
    }
}

inline void rbDSU::unite(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy){
        return;
    }
    father[fx]=fy;
    history.push({fx,fy,0});
    

}