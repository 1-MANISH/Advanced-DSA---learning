// 2 sum III
#include<bits/stdc++.h>
using namespace std;



int main(){

	long long int n ,t;
	cin >> n>> t;
	vector<long int>arr(n);
	unordered_map<long long int,int>mp;
	for(int i = 0 ; i < n ; i++) cin >> arr[i],mp[arr[i]]++;
	long long int pairs = 0;
	for(int i = 0  ; i< n ; i++){
		if(mp[arr[i]]!=-1){
			int eleFreq = mp[arr[i]];
			int isPossibleFreq = mp[t - arr[i]]; 
			if(arr[i]==t-arr[i]){
				pairs+=((1LL*eleFreq*(eleFreq-1))/2);
				mp[arr[i]]=-1;
				mp[t-arr[i]]=-1;
			}
			else if(isPossibleFreq ){
				pairs+= 1LL*eleFreq*isPossibleFreq;
				mp[arr[i]]=-1;
				mp[t-arr[i]]=-1;
			}
		}
		
	}
	cout << pairs << endl;



	
	return  0;
}