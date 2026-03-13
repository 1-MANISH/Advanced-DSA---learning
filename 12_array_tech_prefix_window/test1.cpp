// range query sum

/*
input:
5
1 2 3 4 5
3
1 3 
2 4
1 5
output:
6
9
15
*/
#include<bits/stdc++.h>
using namespace std;



int main(){


	int n;
	cin >> n;
	vector<int>arr(n+1);
	vector<long long int>pSum(n+1,0);
	for(int i = 1 ; i<= n ; i++)
		cin>>arr[i];
	for(int i = 1 ; i<=n ; i++)
		pSum[i]=pSum[i-1]+arr[i];	

	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l>>r;
		cout << 0LL+pSum[r]-pSum[l-1]<< endl;
	}
	return  0;
}