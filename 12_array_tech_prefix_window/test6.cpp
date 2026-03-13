
/*
Count numbers with eaxctly K factors

arr(N)
K

for each query count numbers in array have
eaxctly K factors

1<=N,Q <=10^5
1<=k<=10^5
1<=A[i]<=10^5
1<=L,R<=N

Input:
5 3 4
6 9 10 15 16
1 3
2 5
1 5

output:
2
2
3


*/
#include<bits/stdc++.h>
using namespace std;



int main(){

	int n , q, t;
	cin >> n >> q >> t;
	vector<int>arr(n+1,0);
	for(int i =1 ; i<= n ; i++) cin >> arr[i];

	vector<int>pdSum(n+1,0);
	for(int i = 1  ; i <= n ;i++){
		int factor = 1 , factorCount = 0;
		while(factor<=arr[i]/factor){
			int j = arr[i]/factor;
			if(arr[i]%factor==0){
				if(j==factor)factorCount++;
				else factorCount+=2;
			}
			factor++;
		}
		pdSum[i]=pdSum[i-1]+(factorCount==t?1:0);
	}

	while(q--){
		int l,r;
		cin >> l >> r;
		cout << pdSum[r]-pdSum[l-1] << endl;

	}
	
	return  0;
}