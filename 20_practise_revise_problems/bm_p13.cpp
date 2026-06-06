#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){

	int N;
	cin >> N;
	map<ll,ll>mp;
	for(int i = 0 ; i < N ; i++){
		ll arrEle;
		cin >> arrEle;
		mp[arrEle]++;
	}
	for(auto &ele:mp){
		if(ele.second==1){
			cout << ele.first<<" ";
		}
	}

	return 0;
}