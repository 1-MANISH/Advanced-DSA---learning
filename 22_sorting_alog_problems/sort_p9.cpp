
#include<bits/stdc++.h>
using namespace std;
int main(){

	int n ;
	cin >> n;
	vector<int>temps(101,0);
	for(int i = 0 ; i < n ; i++) {
		int temp;
		cin >> temp;
		temps[temp+50]++;
	}
	
	for(int i = -50 ; i<=50 ; i++){
		while(temps[i+50]>0){
			cout << i << " ";
			temps[i+50]--;
		}
	}
	
	
	return 0;
}