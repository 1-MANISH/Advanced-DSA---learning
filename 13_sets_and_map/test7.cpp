// F. Intersection of Two Arrays

#include<bits/stdc++.h>
using namespace std;



int main(){

	int n,m;
	cin >> n;
	map<int,int>mp;
	for(int i = 0 ;i < n ; i++){
		int ele;
		cin >> ele;
		mp[ele]++;
	}
	cin >> m;
	vector<int>output;
	for(int i = 0 ; i < m ;i++){
		int ele;
		cin >> ele;
		auto it = mp.find(ele);
		if(it!=mp.end()){
			output.push_back(ele);
			mp.erase(it);
		}
	}
	sort(output.begin(),output.end());
	cout << output.size()<< endl;
	for(auto &ele:output){
		cout << ele << " ";
	}
	if(output.size()==0)cout <<" "<< endl;


	
	return  0;
}