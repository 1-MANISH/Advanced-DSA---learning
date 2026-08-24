#include<bits/stdc++.h>
using namespace std;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;



// K-th Largest Element in an Array

int kthLargetElement(vector<int>&arr,int &k){
	MinHeap<int>min_heap;
	for(int &ele:arr){
		min_heap.push(ele);
		if(min_heap.size()>k){
			min_heap.pop();
		}
	}
	return min_heap.top();
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++) cin >> arr[i];
	cout << kthLargetElement(arr,k);
	return 0;
}