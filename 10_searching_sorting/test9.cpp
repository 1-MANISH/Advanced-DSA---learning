
//spiral order [print]
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , count = 0 ,rowStart = 0,rowEnd = n-1 ,colStart = 0 ,colEnd=m-1 ;
        int totalElement = n*m;
        vector<int>output;
        while(count<totalElement){
            
            //right travel
            for(int col=colStart ; col <=colEnd && count < totalElement ; col++,count++){
                output.push_back(matrix[rowStart][col]);
            }
            rowStart++;
            // last col travel
            for(int row=rowStart ;row <=rowEnd && count < totalElement ; row++,count++){
                output.push_back(matrix[row][colEnd]);
            }
            colEnd--;
            // left travel 
            for(int col=colEnd ; col>=colStart && count <totalElement ; col--,count++){
                output.push_back(matrix[rowEnd][col]);
            }
            rowEnd--;
            // above travel
            for(int row=rowEnd ; row>=rowStart && count <totalElement; row--,count++){
                output.push_back(matrix[row][colStart]);
            }
            colStart++;
        }
        return output;
}

void printArr(vector<int>& spOrder){
	int n = spOrder.size();
	for(int i = 0 ; i < n ; i++){
	 	cout << spOrder[i] << " ";
	} 
}

int main(){
	 
	int n , m;
	cin >> n >> m;
	vector<vector<int>>matrix(n,vector<int>(m,0));
	for(int i = 0 ; i < n ; i++){
	 	for(int j = 0 ; j < m ; j++){
	 		cin >> matrix[i][j];
	 	}
	} 

	vector<int>spOrder = spiralOrder(matrix);
	printArr(spOrder);
	
	return  0;
}