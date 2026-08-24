#include<bits/stdc++.h>
using namespace std;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

// I. Nearly Sorted
void nearlySorted(vector<int>&arr,int&k){
	priority_queue<int,vector<int>,greater<int>>minHeap;
    int index = 0;
    for(int i =0 ; i < arr.size();i++){
        minHeap.push(arr[i]);
        if(minHeap.size()>k){
            arr[index++]=minHeap.top();
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        arr[index++]=minHeap.top();
        minHeap.pop();
    }
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,k;
	cin >> n >> k ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
	}
	nearlySorted(arr,k);
	for(auto &ele:arr)cout << ele << " ";
	
	return 0;
}