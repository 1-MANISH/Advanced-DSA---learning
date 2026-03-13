
/*
Range Sum of sqaures

Arr A (N)

Q queried

A[L]^2+A[L+1]^2+.........A[R]^2

n,q<=10^5
1<=A[i]<=10^6
1<=L,R<=N

Input:
5 3
2 3 1 4 2
1 3
2 5
4 4

output:
14
30
16

*/
#include<bits/stdc++.h>
using namespace std;



int main(){

	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1 ; i<= n ; i++) cin >> arr[i];

	vector<long long int>psSum(n+1,0);
	for(int i = 1 ; i<=n ; i++){
		psSum[i] = psSum[i-1]+1LL*arr[i]*arr[i];
	}

	while(q--){
		int l,r;
		cin >> l >> r;

		cout << 0LL+psSum[r]-psSum[l-1] << endl;
	}


	
	return  0;
}