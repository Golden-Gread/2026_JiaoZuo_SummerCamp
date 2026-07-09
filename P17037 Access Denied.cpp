#include <bits/stdc++.h>
using namespace std;

string dic="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";


int chk_len(){
	int t;string test="";
	while(t==5){
		test+='A';
		cout<<test;
		string res;cin>>res>>res;
		if(res=="GRANTED"){
			return -1;
		}
		else if(res=="DENIED"){
			cin>>res;sscanf("(%d ms)\n",res.c_str(),&t);
		}
	}
	return test.length();
}

void test_string(int len){
	int t;
	for(int i=0;i<len;i++){
		for(char c)
		string res;cin>>res>>res;
		if(res=="GRANTED"){
			return ;
		}
		else if(res=="DENIED"){
			cin>>res;sscanf("(%d ms)\n",res.c_str(),&t);
		}
	}
}
