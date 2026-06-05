#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed  main(){

	int N;
	cin >> N;

	int ans = 1;
	while(ans<=N){
		cout << ans << " ";
		ans*=2;
	}

	return 0;
}