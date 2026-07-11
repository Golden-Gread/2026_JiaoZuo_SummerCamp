#include<bits/stdc++.h>
using namespace std;
int main(){
	bool z = 0;
	int x,sum = 0,mm = 0,v;
	for (int i = 1; i <= 12; i++){
		cin>>x;
		sum += 300;
		if (sum < x){
			cout<<-i<<endl;
            return 0;
		}
		else {
			sum -= x;
		}
		if (sum >= 100){
			mm += sum / 100 * 100;
			sum %= 100;
		}
	}
	sum += mm + mm * 0.2;
	cout<<sum<<endl;
    return 0;
}
