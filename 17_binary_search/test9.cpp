/*
COUNT ELEMENT > X
1<=Q<=10^5
1<=N<=10^5
*/
#include<bits/stdc++.h>
using namespace std;

int countGreaterThanX(vector<int>&arr,int &n, int &x){
	int s = 0 , e = n-1 , ans = -1  ;
	while(s<=e){
		int m = s+(e-s)/2;
		if(arr[m]>x){
			ans = m;
			e = m-1;	
		}else{
			s = m+1;
		}
	}
	
	return ans==-1?0:n-ans;
}

int main(){

	int n ,q;
	cin >> n >> q;
	vector<int>arr(n);
	for(int i   = 0 ; i < n ; i++)
		cin >> arr[i];
	sort(arr.begin(),arr.end());	
	while(q--){
		int x;
		cin >> x;
		cout << countGreaterThanX(arr,n,x) << endl;
	}

}