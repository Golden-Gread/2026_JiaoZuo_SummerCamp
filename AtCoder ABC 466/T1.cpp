#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x>=0) {cout<<"No";return 0;}
    }
    cout<<"Yes";
    return 0;
}