/*
Q:
Count elements
element>=a and ele<=b
*/
#include<bits/stdc++.h>
using namespace std;

int countElementsCon(vector<int>&arr,int &n, int &a,int &b){
	int s = 0 , e  = n-1 , ans = -1;
	while(s<=e){
		int m = s + (e-s)/2;
		if(arr[m]<=b){
			ans = m;
			s = m+1;
		}else{
			e = m-1;
		}
	}
	if(ans==-1)return 0;
	s = 0,e = n-1;
	int ans2=-1;
	while(s<=e){
			int m = s+(e-s)/2;
			if(arr[m]>=a){
				ans2 = m;
				e = m-1;
			}else{
				s = m+1;
			}
	}
	return ans>ans2 ? ans-ans2+1:0;
	
}

int main(){

	int n ,q;
	cin >> n >> q;
	vector<int>arr(n);
	for(int i   = 0 ; i < n ; i++)
		cin >> arr[i];
	sort(arr.begin(),arr.end());
	while(q--){
		int a,b;
		cin >> a >> b;
		cout <<countElementsCon(arr,n,a,b) << endl;
	}

}