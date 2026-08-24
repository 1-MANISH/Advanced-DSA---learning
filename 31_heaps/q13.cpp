#include<bits/stdc++.h>
using namespace std;

template <typename T>
using MaxHeap = priority_queue<T>;


vector<int> kClosetElements(vector<int>&arr,int&k,int &x){
	MaxHeap<pair<int,int>>max_heap;//{dist,element};
	for(auto &ele:arr){
		int dist = abs(x-ele);
		max_heap.push({dist,ele});
		if(max_heap.size()>k){
			max_heap.pop();
		}
	}
	vector<int>output(k);
	for(int i = 0 ; i <k ;i++){
		output[i]=max_heap.top().second;
		max_heap.pop();
	}
	sort(output.begin(),output.end());
	return output;
}


int main(){
	int n,k,x;
	cin >> n >> k >> x;
	vector<int>elements(n);
	for(int i = 0 ; i< n ; i++){
		cin >> elements[i];
	}
	vector<int> closests = kClosetElements(elements,k,x);
	for(auto &ele:closests)cout << ele << " ";
	
	return 0;
}