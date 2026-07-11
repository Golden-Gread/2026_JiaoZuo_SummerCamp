#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum=0,x,sum1=0,money=0;
	for(int i=0;i<12;i++){
		cin>>x;money+=300;money-=x;
		
		if(money>=100) {sum+=(money/100)*100;money=money%100;}
		if(money<0){cout<<-(i+1);return 0;}
		
	}
	sum1+=money;
	sum1+=sum*1.2;
	cout<<sum1;
	return 0;
	
	
}