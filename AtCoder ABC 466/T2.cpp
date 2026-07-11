#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> ball(105,-1);

int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        ball[a]=max(ball[a],b);
    }

    for(int i=1;i<=m;i++){
        cout<<ball[i]<<" ";
    }
    return 0;    
}