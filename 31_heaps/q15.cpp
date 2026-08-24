#include<bits/stdc++.h>
using namespace std;

template <typename T>
using MaxHeap = priority_queue<T>;

// J. The K Weakest Rows in a Matrix

vector<int> weekestRows(vector<vector<int>>&matrix,int &k){
	MaxHeap<pair<int,int>>max_heap;//{solderCount,row}
	for(int i = 0 ; i < matrix.size();i++){
		int solderCount = 0;
		for(auto &ele:matrix[i])solderCount+=ele;
		max_heap.push({solderCount,i});
		if(max_heap.size()>k){
			max_heap.pop();
		}
	}
	vector<int>output(k);
	for(int i = k-1; i>=0 ; i--){
		output[i]=max_heap.top().second;
		max_heap.pop();
	}
	return output;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>>matrix(n,vector<int>(m,0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0  ; j < m ; j++)
			cin >> matrix[i][j];
	}
	vector<int>output = weekestRows(matrix,k);
	for(auto &ele:output)cout << ele << " ";
	return 0;
}