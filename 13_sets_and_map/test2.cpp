// unions of 2 arrays (No duplicates)
#include<bits/stdc++.h>
using namespace std;



int main(){

	int n ;
	cin >> n;
	vector<int>a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	int m;
	cin >> m;
	vector<int>b(m);
	for(int j = 0 ; j < m ; j++) cin >> b[j];

	set<int>us;
	for(auto &ele:a)us.insert(ele);
	for(auto &ele:b)us.insert(ele);

	cout << us.size() << endl;
	for(auto &ele:us)cout << ele << " ";


	
	return  0;
}