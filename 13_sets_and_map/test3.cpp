// unions of 2 arrays ( duplicates)
#include<bits/stdc++.h>
using namespace std;

// max occureance
//  n times  - n max occurance

int main(){

	
	int n , m;
	cin >> n >> m;
	vector<int>a(n);
	vector<int>b(m);

	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int j = 0 ; j < m ; j++) cin >> b[j];

	unordered_map<int,int>am;
	unordered_map<int,int>bm;
	for(auto &ele:a)am[ele]++;
	for(auto &ele:b)bm[ele]++;
	for(auto &ptr:am){
		int mx = max(ptr.second,bm[ptr.first]);
		while(mx--){
			cout << ptr.first << " ";
		}
		if(bm.find(ptr.first)!=bm.end()){
			bm.erase(ptr.first);
		}
	}
	for(auto &ptr:bm){
		int count = ptr.second;
		while(count--){
			cout << ptr.first << " ";
		}
	}

	



	
	return  0;
}