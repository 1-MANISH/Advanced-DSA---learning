
/*
Count numbers with digit sum K

arr(N)
K

for each query count numbers in array have
digit sum ==K

1<=N,Q <=10^5
1<=k<=100
1<=A[i]<=10^9
1<=L,R<=N

Input:
5 3 10
19 55 10 37 91
1 3
2 5
1 5

output:
2
3
4

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
		int digitSum = 0 ;
		int number  = arr[i];
		while(number>0){
			digitSum+=number%10;
			number/=10;
		}
		// contribution addition
		pdSum[i]=pdSum[i-1]+(digitSum==t ? 1:0);
	}

	while(q--){
		int l,r;
		cin >> l >> r;
		cout << pdSum[r]-pdSum[l-1] << endl;

	}
	
	return  0;
}