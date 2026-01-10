#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >>t;
	while(t--){
		int n ,q;
		cin >> n >> q;
		vector<int>arr(n+1);
		vector<int>forward(n+1,0);
		vector<int>backward(n+1,0);
		for(int i = 1 ; i <= n ; i++){
			cin >> arr[i];
			forward[i]=__gcd(forward[i-1],arr[i]);
		}
		backward[n]=arr[n];
		for(int i = n-1 ; i >= 1 ; i--){
			backward[i]=__gcd(backward[i+1],arr[i]);
		}
		while(q--){
			int l,r;
			cin >> l >> r;
			// calculate GCD(arr[1...l-1 and r+1...n])
			int answer = __gcd(forward[l-1],backward[r+1]);
			// for(int index=0 ; index <=l-1 ; index++){
			// 	answer = __gcd(answer,arr[index]);
			// }
			// for(int index=r+1 ; index <=n ; index++){
			// 	answer = __gcd(answer,arr[index]);
			// }
			cout << answer << endl;
		}
	}

	
	
	return 0;
}

// TC= O(n)+O(q)= O(n)