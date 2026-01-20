// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
#include<bits/stdc++.h>
using namespace std;


// brute force
// bool isValidSubstringWithLeastK(unordered_map<char,int>&countMap,int &k){
// 	int m = countMap.size() , counts = 0;
// 	for(auto &ele:countMap){
// 		if(ele.second<k)return false;
// 		else counts++;
// 	}
// 	return m==counts;
// }

// int longestSubstring(string s, int k) {
// 	int n = s.size() , maxLen = 0;
//     for(int i = 0 ; i < n ; i++){
//     	unordered_map<char,int>countMap;
//     	for(int j = i ; j < n ; j++){
//     		countMap[s[j]]++;
//     		if(isValidSubstringWithLeastK(countMap,k)){
//     			cout << i << " " << j << endl;
//     			maxLen = max(maxLen,j-i+1);
//     		}
//     	}
//     }
//     return maxLen;
// }

// Divide and  conquer mechanism

int helper(string &s,int start , int end, int &k , int &n ){
	if(start>=end){
		return 1>=k ? 1:0;
	}
	vector<pair<int,int>>countMap(26,{0,INT_MAX});
	for(int i = start ; i <= end ; i++){
		countMap[s[i]-'a']={++countMap[s[i]-'a'].first,i};
	}
	int mid = -1 , counts = 0 , m = 0 ;
	for(int i = 0; i< 26;i++){
		if(countMap[i].first && countMap[i].first<k){
			mid=countMap[i].second;
			break;
		}
		if(countMap[i].first>=k)counts++;
		if(countMap[i].first)m++;
	}
	if(mid!=-1){
		int leftMax = helper(s,start,mid-1,k,n);
		int rightMax = helper(s,mid+1,end,k,n);
		return max(leftMax,rightMax);
	}else{
		// if valid 
		if(counts==m)
			return end-start+1;
		else return 0;
	}

}

int longestSubstring(string &s,int &k){
	int n = s.size();
	return helper(s,0,n-1,k,n);
}


int main(){

	string s;
	int k;
	cin >> s >> k;
	cout << longestSubstring(s,k) << endl;

	return 0;
}