#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<vector<int>>arr(N,vector<int>(N,0));
vector<vector<int>>prefixRowSum(N+1,vector<int>(N+1,0));


/*

Given a 2D array of N x N integers. Guven Q
queried and in each query given a ,b c,d . print sum
of square represented by (a,b) top left point and
(c,d) as  bottom right point


1<=n<=10^3
1<=a[i][j]<=10^9
1<=q<=10^5
1<=a,b,c,d<=n

*/


// TC =  (N^2) * O(Q) => 10^11
int bruteForce(int &a,int &b , int &c,int &d){
	int sum = 0;
	for(int i = a ; i <= c ; i++){
		for(int j = b ; j <= d ; j++ ){
			sum+=arr[i][j];
		}
	}
	return sum;

}
// TC =  (N^2) + q*O(a+c) => 10^6 + 10^5*10^3 = >10^8
void slightlyOptimizedUsingPrefixRowSum(int &n){
	for(int i = 1 ; i <=  n ; i++){
		prefixRowSum[i][1]=arr[i-1][0];
		for(int j = 2  ; j <= n ; j++){
			prefixRowSum[i][j]=prefixRowSum[i][j-1]+arr[i-1][j-1];
		}
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> arr[i][j];
		}
	}

	// pre computations
	slightlyOptimizedUsingPrefixRowSum(n);

	int q;
	cin >> q;
	while(q--){
		int a,b,c,d;
		cin >> a >> b >>c >>d;
		// cout << bruteForce(a,b,c,d) << endl;
		int result=0;
		for(int i = a ; i<= c ; i++){
			result+=(prefixRowSum[i][d] - prefixRowSum[i][b-1]);
		}
		cout << result << endl;
	}
	
	return 0;
}
