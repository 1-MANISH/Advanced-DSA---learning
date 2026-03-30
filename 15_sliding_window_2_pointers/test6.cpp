
/*
Q:
COUNT SUBARRAYS WITH NO DUPLICATES

*/
#include<bits/stdc++.h>
using namespace std;


int countSubArraysWithNoDuplicates(vector<int>&arr,int &n){

	int ans  = 0;
	unordered_map<int,int>freq;
	int l = 0;
	for(int r = 0  ; r < n ;r++){
		freq[arr[r]]++;
		while(l<n && freq[arr[r]]>1){
			freq[arr[l]]--;
			l++;
		}
		ans+=(r-l+1);
	}
	return ans;

}

int main(){

	int n;
    cin >> n ;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    cout << countSubArraysWithNoDuplicates(arr,n) << endl;
	
	return  0;
}