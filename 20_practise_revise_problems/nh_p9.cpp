#include<bits/stdc++.h>
using namespace std;



int main(){

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N=1e6;
	vector<int>spf(N+1,1);
	for( int i=2;i<=N;i++) spf[i]=i;
	for( int i=2;i<=N/i;i++){
		if(spf[i]==i){
			for( int j=i*i;j<=N;j+=i){
				spf[j]=min(spf[j],i);
			}
		}
	}

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		if(n<=1){cout<<""<<endl;continue;}
		 int currentFactor=spf[n],count=1;
		while(spf[n]!=n){
			int newFactor=spf[n/currentFactor];
			n/=currentFactor;
			if(newFactor==currentFactor)count++;
			else {
				cout << currentFactor<<"^"<<count<< " ";
				currentFactor=newFactor;
				count=1;
			}
		}
		cout << currentFactor<<"^"<<count<<endl;
	}

	

	return 0;
}