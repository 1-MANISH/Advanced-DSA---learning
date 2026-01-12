#include<bits/stdc++.h>
using namespace std;

/*
	Nesting Vectors

	vector<data_type>arr;
	vector<container>arr;
	vector<pair<int,int>>={{},{}};
	vector<vector<int>>2dArray;
	make_pair(a,b) or {a,b}


	Arrays of vectors
	vector<int> arr[n]; //10 vector with zero size
	fixed size
	Number or rows fixed


	Vectors of vectors
	vector<vector<int>>(N);
	Dynamic - rows and cols
	.push_back()
	.push_back(vector<int>())
	.pop_back()


*/

void printVector(vector<pair<int,string>>&arr,int &n){
	for(int i = 0  ; i < n ; i++){
		cout << arr[i].first << " - > " << arr[i].second << endl;
	}
}
void print2DVector(vector<vector<int>>&arr,int &n){
	for(int i = 0  ; i < n ; i++){
		for(int j = 0 ; j< arr[i].size() ; j++){
			cout << arr[i][j] << " ";
		}cout << endl;
	}cout << "---------------" << endl;
}
int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>>arr(n);
		for(int i = 0 ; i < n ; i++){
			int m,x;
			cin >> m;
			for(int j = 0 ; j < m ; j++){
				cin >> x;
				arr[i].push_back(x);
			}
		}
		print2DVector(arr,n);
	}



	/*
	vector<pair<int,string>>arr(n);
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i].first >> arr[i].second;
	}

	printVector(arr,n);

	*/
	
	return 0;
}