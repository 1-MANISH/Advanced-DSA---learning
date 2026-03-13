
// even sum queries

/*

Input:
5
1 2 3 4 5
3
1 3 
2 4
1 5

output:
2
6
6
*/

#include<bits/stdc++.h>
using namespace std;



int main(){

	int n;
	cin >> n;
	vector<int>arr(n+1,0);
	for(int i = 1 ; i <= n ; i++) cin >> arr[i];

	vector<long long int>evenPSum(n+1,0);
	long long int sum = 0 ;
	for(int i = 1 ; i<=n ; i++){
		if(i%2==0){
			sum+=arr[i];
		}
		evenPSum[i]=sum;
	}

	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;

		cout << 0LL+evenPSum[r]-evenPSum[l-1] << endl;

	}


	
	return  0;
}