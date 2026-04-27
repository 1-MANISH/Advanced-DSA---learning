#include<bits/stdc++.h>
using namespace std;

const int N = 2*(1e5)+10;


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int>spf(N,1);
	for(int i = 2 ; i <N ; i++)
		spf[i]=i;

	for(int i = 2 ; i*i < N ; i++){
		if(spf[i]==i){
			for(int j = i*i ; j < N ; j+=i){
				spf[j]=min(spf[j],i);
			}
		}
	}

	int q;
	cin >> q;
	while(q--){
		int n ,  k;
		cin >> n >> k;
		int count = 0 , kp  =  -1 ;
		while(n!=1 ){
				count++;
				if(count==k){
					kp = spf[n];
					break;
				}
				n /=spf[n];
		}
		if(k>count)
			cout << -1 << "\n";
		else
			cout << kp << "\n";

	}

	
	return 0;
}