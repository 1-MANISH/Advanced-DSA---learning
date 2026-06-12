
#include<bits/stdc++.h>
using namespace std;



int main(){

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int mx=INT_MIN,mn=INT_MAX;
		for(int i = 0 ; i< n ; i++){
			int ele;
			cin >> ele;
			mx = max(mx,ele);
			mn = min(mn,ele);
		}
		cout << mx-mn+1 << endl;
	}
	
	return 0;
}