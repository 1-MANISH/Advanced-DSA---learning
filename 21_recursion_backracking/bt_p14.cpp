
#include<bits/stdc++.h>
using namespace std;
const int n = 9;

bool isValid(vector<vector<char>>&sudoku,int &row,int &col,char &num){

	// col check
	for(int j = 0 ; j< n ; j++){
		if(sudoku[row][j]==num)return false;
	}
	// row check
	for(int i = 0 ; i< n ; i++){
		if(sudoku[i][col]==num)return false;
	}

	// area check
	int i = (row/3)*3 , j = (col/3)*3;
	for(int r = i  ;r < i+3 ; r++){
		for(int c = j ; c < j+3 ; c++){
			if(sudoku[r][c]==num)return false;
		}
	}

	return true;
}

void solveSudoku(vector<vector<char>>&sudoku,int row ,int col){

	if(row>=n-1 && col>=n){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cout << sudoku[i][j]<< "";
			}cout << endl;
		}
		return;
	}

	if(col<n ){
		if(sudoku[row][col]=='.'){
			for(char num='1';num<='9';num++){
				if(isValid(sudoku,row,col,num)){
					sudoku[row][col]=num;
					solveSudoku(sudoku,row,col+1);
					sudoku[row][col]='.';
				}
			}
		}else{
			solveSudoku(sudoku,row,col+1);
		}
	}else if(col>=n){
		solveSudoku(sudoku,row+1,0);
	}

}


int main(){
	
	vector<vector<char>>sudoku(n,vector<char>(n,'.'));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> sudoku[i][j];
		}
	}
	solveSudoku(sudoku,0,0);

	

	return 0 ;
}