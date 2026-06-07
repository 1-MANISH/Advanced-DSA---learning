#include<bits/stdc++.h>
using namespace std;

void printAllPossiblePath(vector<vector<int>>&grid,int &n,int &m,int i,int j ,string &path){

	if(i==n-1 && j == m-1){
		cout << path<<endl;
		return;
	}
	if(i>=n || j>=m)
		return;

	// lets take right- if possible
	if(grid[i][j]==0){
		path.push_back('R');
		printAllPossiblePath(grid,n,m,i,j+1,path);
		path.pop_back();
	}

	// lets take down - if possible
	if(grid[i][j]==0){
		path.push_back('D');
		printAllPossiblePath(grid,n,m,i+1,j,path);
		path.pop_back();
	}
	
}

int main(){

	int n,m;
	string path = "";
	cin >> n >> m;
	vector<vector<int>>grid(n,vector<int>(m,0));
	for(int i = 0  ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> grid[i][j];
		}
	}

	printAllPossiblePath(grid,n,m,0,0,path);

	return 0;
}