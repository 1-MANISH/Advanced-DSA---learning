#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<long long int>&woodLog,long long int &mid, long long int &n,long long int &k){
	long long int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		count+=0LL+woodLog[i]/mid;
	}
	return count>=k;
}

int main(){

	long long int n,k;
	cin >> n >> k;
	vector<long long int>woodLog(n);
	for(int i = 0 ; i < n ; i++)
		cin >> woodLog[i];


	long long int ans = 0 ,  
	start = 1 , 
	end = *max_element(woodLog.begin(),woodLog.end());


	while(start<=end){
		long long int mid = start+(end-start)/2;
		if(isValid(woodLog,mid,n,k)){
			ans = mid;
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	cout << ans ;

	
	return 0;
}