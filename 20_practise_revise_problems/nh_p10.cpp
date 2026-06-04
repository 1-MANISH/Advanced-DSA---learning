#include<bits/stdc++.h>
using namespace std;



int main(){

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N=5*1e6;
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
	int uniquePrime=0;
	int i=2;
	while(i<=q){
		int n=i;
		int currentFactor=spf[n],count=1;
		while(spf[n]!=n){
			int newFactor=spf[n/currentFactor];
			n/=currentFactor;
			if(newFactor!=currentFactor)
			{
				currentFactor=newFactor;
				count++;
			}
		}
		if(count==2)uniquePrime++;
		i++;
	}
	cout << uniquePrime<<endl;

	

	return 0;
}