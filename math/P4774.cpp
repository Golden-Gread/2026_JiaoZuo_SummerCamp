#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

multiset<ll> s;

int exGCD(int a, int b, int &x, int &y) {//Ax+By=GCD(a,b)
    if (b == 0) {
        x = 1;y = 0;
        return a;
    }
    int gcd = exGCD(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int main(){
    
}

