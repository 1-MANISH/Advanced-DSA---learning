
// count dist
#include<bits/stdc++.h>
using namespace std;



int main(){

	int n;
	cin >> n;
	unordered_set<int>us;
	for(int i = 0 ; i < n ; i++){
		int ele;
		cin >> ele;
		us.insert(ele);
	}
	cout << us.size() << endl;


	
	return  0;
}