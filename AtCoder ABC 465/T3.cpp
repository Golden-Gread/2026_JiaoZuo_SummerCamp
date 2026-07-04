#include <bits/stdc++.h>
using namespace std;

void reverse(int l,int r,vector<int> &v){
    reverse(v.begin()+1,v.begin()+r+1);
//swap(v[l],v[r]); swap(v[l+1],v[r-1]); swap(v[l+2],v[r-2]); swap(v[l+3],v[r-3]); swap(v[l+4],v[r-4]); swap(v[l+5],v[r-5]); swap(v[l+6],v[r-6]); swap(v[l+7],v[r-7]); swap(v[l+8],v
}



int main() {
    int n;string s;
    cin >> n >> s;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) v[i]=i;
    for(int i=0;i<n;i++){
        if(s[i]=='o'){
            reverse(1,i+1,v);
        }
    }

    for(int i=1;i<=n;i++) cout << v[i] << " ";

    return 0;  //return 0;
}

