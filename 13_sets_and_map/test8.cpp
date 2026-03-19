// G. Intersection of Two Arrays II

#include<bits/stdc++.h>
using namespace std;



int main(){

	int n,m;
	cin >> n;
	unordered_map<int,int>a;
	unordered_map<int,int>b;
	for(int i = 0 ;i < n ; i++){
		int ele;
		cin >> ele;
		a[ele]++;
	}
	cin >> m;
	vector<int>output;
	for(int i = 0 ; i < m ;i++){
		int ele;
		cin >> ele;
		b[ele]++;
	}
	for(auto &ele:a){
		int mn = min(a[ele.first],b[ele.first]);
		while(mn--)output.push_back(ele.first);
	}
	sort(output.begin(),output.end());
	cout << output.size()<< endl;
	for(auto &ele:output){
		cout << ele << " ";
	}
	if(output.size()==0)cout <<" "<< endl;


	
	return  0;
}