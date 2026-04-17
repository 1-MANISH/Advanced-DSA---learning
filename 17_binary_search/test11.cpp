/*
Q:
Binary search on aggresive cows
Tc = O( log ( maxEle-minEle) * N )
Sc = O(1)
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&position,int &n,int &m,int &k){
	int cowCount = 1 , p_index = 0;
	for(int i = 1 ; i< n ; i++ ){
		int d = position[i]-position[p_index];
		if(d<m)continue;
		else{
			cowCount++;
			p_index=i;
		}
	}
	if(cowCount<k)return false;
	else return true;
}

int maxMinDistance(vector<int>&position,int &n,int &k){
	// sort(position.begin(),position.end());
	int mx  = INT_MIN ,  mn = INT_MAX;
	for(auto &ele:position){
		mn =  min(mn,ele);
		mx = max(mx,ele);
	}
	int s  = 0 , e = position[n-1]-position[0] , ans = -1;
	while(s<=e){
		int m = s+(e-s)/2;
		if(isPossible(position,n,m,k)){
			ans = m;
			s=m+1;
		}else{
			e = m-1;
		}
	}
	return ans;
}

int main(){

	int n  , k ;
	cin >> n >> k;
	vector<int>position(n);
	for(int i = 0 ; i < n ; i++)
		cin >> position[i];

	
	cout << maxMinDistance(position,n,k)<< endl;
}