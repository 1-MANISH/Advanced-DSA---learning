#include<bits/stdc++.h>
using namespace std;



int main(){

	int n , q;
	cin >> n >> q;

	unordered_map<int,int>um;
	for(int i = 0 ; i< n ; i++){
		int ele;
		cin >> ele;
		um[ele] = i+1;
	}

	while(q--){
		int x;
		cin >> x;
		cout << (um[x]==0?-1:um[x]) << endl;
	}


	
	return  0;
}