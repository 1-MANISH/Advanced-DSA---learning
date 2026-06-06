#include<bits/stdc++.h>
using namespace std;

int main(){

	int N;
	cin >> N;
	unordered_map<int,int>mp;
	for(int i = 0 ; i < N ; i++){
		int arrEle;
		cin >> arrEle;
		mp[arrEle]++;
	}
	for(auto &ele:mp){
		if(ele.second==1){
			cout << ele.first<<endl;
		}
	}

	return 0;
}