#include<bits/stdc++.h>
using namespace std;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;



// F. Top K Frequent Elements

vector<int> topKFrequentElements(vector<int>&arr,int &k){
	vector<int>output(k);
	MinHeap<pair<int,int>>min_heap;//{freq,element}
	unordered_map<int,int>freq;
	for(auto &ele:arr)freq[ele]++;
	for(auto &[ele,count]:freq){
		min_heap.push({count,ele});
		if(min_heap.size()>k)
			min_heap.pop();
	}
	for(int i = k -1 ; i >=0 ; i--){
		output[i]=min_heap.top().second;
		min_heap.pop();
	}
	return output;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++) cin >> arr[i];
	vector<int> output = topKFrequentElements(arr,k);
	for(auto &ele:output)cout << ele << " ";
	return 0;
}