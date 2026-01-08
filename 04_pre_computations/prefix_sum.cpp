#include<bits/stdc++.h>
using namespace std;

int main(){

	int N;
	cin >> N;
	vector<int>arr(N);
	for(int i = 0 ; i < N ;i++)cin >> arr[i];

	vector<int>prefixSum(N+1,0);
	prefixSum[1]=arr[0];
	for(int i = 2 ; i <= N ; i++)prefixSum[i]=prefixSum[i-1]+arr[i-1];

	int Q;
	cin >> Q;
	while(Q--){
		int L,R;
		cin >> L >> R;
		cout << prefixSum[R]-prefixSum[L-1] << endl;
	}	

	
	
	return 0;
}

// TC= O(n)+O(q)= O(n)