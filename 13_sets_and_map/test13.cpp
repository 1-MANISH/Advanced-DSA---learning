// L.Count  Subarray with Sum Equals X
#include<bits/stdc++.h>
using namespace std;



int main(){

	long long int n , x;
	cin >> n >> x;
	vector<long long int>arr(n);
	for(int i =  0 ; i < n ; i++) cin >> arr[i];
	unordered_map<long long int,long long int>mp;
	long long int prev_sum = 0;	
	long long int count =0 ;
	mp[0]=1;
	for(int i = 0 ; i < n ; i++){
		prev_sum+=arr[i];
		long long int rem = prev_sum-x;
// 		cout << rem <<" : "<<mp[rem] << endl;
// 		cout <<( mp.find(rem)==mp.end()) << endl;
		bool isPoss = mp.find(rem)==mp.end()?false:true;
		if(isPoss){
		    count+=mp[rem];
		}
		mp[prev_sum]++;
	}	
	cout <<count<< endl;
	return  0;
}