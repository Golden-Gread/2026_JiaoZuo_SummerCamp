#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,l,r,a,b;
    cin>>x>>y>>l>>r>>a>>b;
    int ans=0;
    for(int i=a+1;i<=b;i++){
        if(i>l&&i<=r){
            ans+=x;
        }
        else{
            ans+=y;
        }
    }

    cout<<ans;
    return 0;
}
