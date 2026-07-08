#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int exGCD(int a, int b, int &x, int &y) {//Ax+By=GCD(a,b)
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int gcd = exGCD(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}