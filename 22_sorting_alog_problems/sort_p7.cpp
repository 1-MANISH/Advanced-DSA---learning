
#include<bits/stdc++.h>
using namespace std;

bool compare(int &a,int &b){
	return a>b;
}

int main(){

	int n ;
	cin >> n;
	vector<int>count(10,0);
	for(int i = 0 ; i < n ; i++) {
		int ele;
		cin >> ele;
		count[ele]++;
	}
	
	for(int i = 9 ; i>=0 ; i--){
		while(count[i]>0){
			cout << i;
			count[i]--;
		}
	}
	
	
	return 0;
}