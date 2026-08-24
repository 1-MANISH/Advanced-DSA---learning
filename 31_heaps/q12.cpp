#include<bits/stdc++.h>
using namespace std;

template <typename T>
using MaxHeap = priority_queue<T>;



// G. K Closest Points to Origin
vector<vector<int>> kClosestPoints(vector<vector<int>>&points,int &k){
	MaxHeap<pair<float,pair<int,int>>>max_heap;//{dist,{x,y}}
	for(auto &point:points){
		int x = point[0],y =point[1];
		float origin_distance = sqrt(x*x+y*y);
		max_heap.push({origin_distance,{x,y}});
		if(max_heap.size()>k){
			max_heap.pop();
		}
	}
	vector<vector<int>>closests_points(k);
	for(int i = k-1 ; i>=0 ;i--){
		closests_points[i]={max_heap.top().second.first,max_heap.top().second.second};
		max_heap.pop();
	}
	return closests_points;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>>points(n,vector<int>(2,0));
	for(int i = 0 ; i< n ; i++){
		cin >> points[i][0] >> points[i][1];
	}
	vector<vector<int>>closests_points = kClosestPoints(points,k);
	for(auto &point:closests_points){
		cout << point[0] << " "<< point[1] << endl;
	}
	return 0;
}