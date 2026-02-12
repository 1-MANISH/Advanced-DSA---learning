#include<bits/stdc++.h>
using namespace std;


int main(){

	int n ;
	cin >> n ;
	vector<long long int>arr(n);
	for(int i = 0  ; i < n ; i++){
		cin >> arr[i];
	}
	
	for(long long int i = 0 ; i <n ; i++){
		if(arr[i]<=2){
			cout << "NO\n";
			continue;
		}
		int count = 2 ;
		long long int m = 2;
		while(count <= 3 && m <arr[i]){
			if(arr[i]%m==0)count++;
			m++;
		}
		if(count==3){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

	return 0;
}

/*

10
4 5 9 1 2 11 17 25 49 78
*/