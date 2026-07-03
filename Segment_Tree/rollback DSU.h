#include<vector>
#include<stack>

class rbDSU{
    private:
        std::vector<int> father;
        std::stack<int> history;
    public:
        int find(int x);
        void unite();
};