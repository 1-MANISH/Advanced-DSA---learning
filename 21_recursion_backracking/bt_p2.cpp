
#include<bits/stdc++.h>
using namespace std;


void printPath(vector<int>&path){
	for(int &ele:path)cout << ele << " ";
	cout << endl;
}

void printAllValidPath(int &n,int &k,int rem,vector<int>&path){

	if(rem==0){
		printPath(path);
		return;
	}

	for(int i = 1 ; i <= k ; i++){

		// possible to take this steps lets just check and call

		if(rem>=i){
			path.push_back(i);
			printAllValidPath(n,k,rem-i,path);
			path.pop_back();
		}
	}
}


int main(){

	int n  , k ;
	cin >> n >> k;
	vector<int>path;

	printAllValidPath(n,k,n,path);
	

	return 0;
}