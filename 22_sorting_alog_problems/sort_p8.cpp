
#include<bits/stdc++.h>
using namespace std;

bool compare(int &a,int &b){
	return a>b;
}

int main(){

	int n ;
	cin >> n;
	vector<int>ages(101,0);
	for(int i = 0 ; i < n ; i++) {
		int age;
		cin >> age;
		ages[age]++;
	}
	
	for(int i = 0 ; i<=100 ; i++){
		while(ages[i]>0){
			cout << i << " ";
			ages[i]--;
		}
	}
	
	
	return 0;
}