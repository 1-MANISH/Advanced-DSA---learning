
#include<bits/stdc++.h>
using namespace std;

void printSubsequence(vector<int>&subSequence){
	if(subSequence.size()==0)return;
	for(auto &ele:subSequence)cout << ele <<  " ";
	cout << endl;
}


void printAllSubsequences(vector<int>&arr,int &n,int i,vector<int>&output){

	if(i==n){
		printSubsequence(output);
		return;
	}

	// not take it
	printAllSubsequences(arr,n,i+1,output);

	// take it
	output.push_back(arr[i]);
	printAllSubsequences(arr,n,i+1,output);
	output.pop_back();

	
}


int main(){

	int n ;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	vector<int>output;
	printAllSubsequences(arr,n,0,output);

	return 0;
}