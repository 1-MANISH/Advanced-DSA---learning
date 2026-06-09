
#include<bits/stdc++.h>
using namespace std;

void solver(vector<int>&candidates,int &c,int &t, int currentSum ,int index,vector<int>&output,vector<vector<int>>&ans){

	if(index==c){
		return;
	}
	if(currentSum==t){
		ans.push_back(output);
		return;
	}
	if(currentSum+candidates[index]>t){
		return;
	}

	
	output.push_back(candidates[index]);
	solver(candidates,c,t,currentSum+candidates[index],index,output,ans);
	output.pop_back();
	solver(candidates,c,t,currentSum,index+1,output,ans);
	
}


int main(){

	int c , t;
	cin >> c >> t;
	vector<int>candidates(c);
	for(int i  = 0 ; i < c ; i++){
		cin >> candidates[i];
	}
	sort(candidates.begin(),candidates.end());

	vector<vector<int>>ans;
	vector<int>output;
	solver(candidates,c,t,0,0,output,ans);

	cout << ans.size() << endl;
	for(auto &comb:ans){
		cout << comb.size() << " ";
		for(auto &ele:comb)cout << ele <<  " ";
		cout << endl;
	}



	return 0 ;
}