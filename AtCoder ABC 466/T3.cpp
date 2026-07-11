#include <bits/stdc++.h>
using namespace std;

bool ask(int x,int y){
    cout << "? " << x << " " << y << endl;
    cout.flush();
    string ans;
    cin >> ans;
    return (ans == "Yes")?true:false;
}

int main(){
    int n;cin >> n;
    int r=1;long long ans=0;
    for(int i=1;i<=n;i++){
        if(r<i) r=i;
        while(r<n){
            if(ask(i,r+1)){
                ++r;
            }
            else{
                break;
            }
        }
        ans+=r-i;
    }

    cout << "! " << ans << endl;
    cout.flush();
    return 0;
}