
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>&board,int &row,int &col,int &n){

	// col check
	for(int i = 0 ; i < n;i++){
		if(board[row][i]=='Q')return false;
	}
	// row check
	for(int i = 0  ; i < n ; i++){
		if(board[i][col]=='Q')return false;
	}

	// digonal check
	int i = row , j = col ;//upperLeft digonal
	while(i>=0 && j>=0){
		if(board[i--][j--]=='Q')return false;
	}
	i = row , j = col ;//downLeft digonal
	while(i<n && j>=0){
		if(board[i++][j--]=='Q')return false;
	}
	return true;
}

void queenPlacer(vector<vector<char>>&board,int i,int j,int n,vector<vector<vector<char>>>&ans){


	if(j==n){
		ans.push_back(board);
		return;
	}


	for(int row=0;row<n;row++){
		if(isValid(board,row,j,n)){
			board[row][j]='Q';
			queenPlacer(board,row,j+1,n,ans);
			board[row][j]='.';
		}
	}
	
}


int main(){

	int n;
	cin >> n;
	vector<vector<char>>board(n,vector<char>(n,'.'));
	vector<vector<vector<char>>>ans;
	queenPlacer(board,0,0,n,ans);
	cout << ans.size() << endl;
	for(auto &b:ans){
		for(auto row:b){
			for(auto &col:row)cout << col;
			cout << endl;
		}cout << endl;
	}

	return 0 ;
}