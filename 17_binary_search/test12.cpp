/*
Q:
Painter partition problem
minimize the max time to paint the wall
Tc = O( log ( maxEle-minEle) * N )
Sc = O(1)
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&time,int &n,int &m,int &k){
	int painter = 1;
	int work = 0;
	for(int i = 0 ; i < n ; i++){
		if(work+time[i]<=m){
			work+=time[i];
		}else{
			painter++;
			work = time[i];
		}
	}	
	return painter<=k;
}

int minMaxTimeToPaint(vector<int>&time,int &n,int &k){
	
	int maxPossibleTime  = 0 , minPossibleTime = INT_MIN;
	for(auto &ele:time){
		maxPossibleTime+=ele;
		minPossibleTime = max(minPossibleTime,ele);
	}

	int s = minPossibleTime ,  e = maxPossibleTime ,  ans = -1;
	while(s<=e){
		int m = s+(e-s)/2;
		if(isPossible(time,n,m,k)){
			ans = m;
			e = m-1;
		}else{
			s = m+1;
		}
	}
	return ans;

}

int main(){

	int n  , k ;
	cin >> n >> k;
	vector<int>time(n);
	for(int i = 0 ; i < n ; i++)
		cin >> time[i];

	
	cout << minMaxTimeToPaint(time,n,k)<< endl;
}