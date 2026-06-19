#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<int>&durability,int &dartPower,int &mid,ll &k){
	ll count = 0 ;
	int n = durability.size();
	for(int i = 1 ; i <= n ; i++){
		int need = ceil(durability[i]/dartPower);
		if(count+need+0LL<=k){
			count+=need;
		}else{
			return false;
		}
	}
	return true;
}

int main(){

	int n,m;
	ll k;
	cin >> n >> m >> k;
	vector<int>durability(n+1,-1);
	vector<int>dartPower(m+1,-1);

	for(int i = 1 ;  i <= n ; i++) cin >> durability[i];
	for(int i = 1 ; i <= m; i++) cin >> dartPower[i];

	sort(durability.begin(),durability.end());
	sort(dartPower.begin(),dartPower.end());

	int start = 0 , end = n , ans  = 0 ;

	while(start<=end){
		int mid = start+(end-start)/2;
		if(isPossible(durability,dartPower[m],mid,k)){
			ans = mid;
			start=mid+1;
		}else{
			end= mid-1;
		}
	}
	cout << ans;		


	return 0;
}