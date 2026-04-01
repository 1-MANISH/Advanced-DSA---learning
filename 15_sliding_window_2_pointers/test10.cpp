
/*
G. Longest Substring with At Most K Distinct Characters

*/
#include<bits/stdc++.h>
using namespace std;


int longestSubstringWithAtMostKDistinctChar(string &s,int &n,int &k){
	int ans = 0 , l = 0 ;
	unordered_map<char,int>freq;
	for(int r = 0 ; r < n ; r++){
		freq[s[r]]++;
		while(l<r && freq.size()>k){
			freq[s[l]]--;
			if(freq[s[l]]==0){
				freq.erase(freq.find(s[l]));
			}
			l++;
		}
		ans = max(ans,r-l+1);
	}
	return ans;
}

int main(){

	int n , k;
	cin >> n >> k ;
	string s;
	cin >> s;

	cout << longestSubstringWithAtMostKDistinctChar(s,n,k);

	
	return  0;
}