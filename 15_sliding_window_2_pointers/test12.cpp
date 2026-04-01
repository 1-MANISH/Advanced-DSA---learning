/*Q:
I. Count Subarrays with At Most K Distinct

1≤N≤10^5
1≤K≤N
1≤Ai≤10^9

*/
#include<bits/stdc++.h>
using namespace std;

long long int countSubArrayWithAtMostKDistinct(vector<int>&arr,int &n ,int &k){
	long long int ans = 0;
	int l = 0 ;
	unordered_map<int,int>freq;
	for(int r = 0 ; r < n ; r++){
		freq[arr[r]]++;
		while(l<r && freq.size()>k){
			freq[arr[l]]--;
			if(freq[arr[l]]==0){
				freq.erase(freq.find(arr[l]));
			}
			l++;
		}
		ans+=r-l+1;
	}
	return ans;
}

int main(){

	int n ,k;
	cin >> n >> k ;
	vector<int>arr(n);
	for(int i = 0 ; i< n ; i++){
		cin >> arr[i];
	}
	cout << countSubArrayWithAtMostKDistinct(arr,n,k);

	
	return  0;
}