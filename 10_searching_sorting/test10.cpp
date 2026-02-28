
//rotate image
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i = 0  ; i < n ; i++){
            for(int j = i  ; j < n ; j++) swap(matrix[i][j],matrix[j][i]);
        }
        // reverse each row
        for(int i = 0  ; i < n ; i++){
            int j = 0 , k = n-1;
            while(j<k)swap(matrix[i][j++],matrix[i][k--]);
        } 
}

void printArr(vector<vector<int>>& matrix){
	int n = matrix.size();
    int m = matrix[0].size();
	for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << matrix[i][j] << " ";
        }cout << endl;
    }  
}

int main(){
	 
	int n , m;
	cin >> n ;
    m = n ;
	vector<vector<int>>matrix(n,vector<int>(m,0));
	for(int i = 0 ; i < n ; i++){
	 	for(int j = 0 ; j < m ; j++){
	 		cin >> matrix[i][j];
	 	}
	} 

	rotate(matrix);
	printArr(matrix);
	
	return  0;
}