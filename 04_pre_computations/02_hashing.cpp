#include<bits/stdc++.h>
using namespace std;

// Array of N integers
// Q queries
// in each query given a number X
// print count of that number in array

// 1<=N<=10^5
// 1<=a[i]<=10^7
// 1<=Q<10^5

const int N = 1e7+10;
int frequency[N];

int main(){

	int n, q, x;
	cin >> n;
	int a[n];
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		frequency[a[i]]++;
	}
	cin >> q;
	while(q--){
		cin >> x;
		cout << frequency[x] << endl;
	}
	
	return 0;
}

// TC= O(n)+O(q)= O(n)