
/*
F. Longest Substring Without Repeating Characters
1≤N≤105

*/
#include<bits/stdc++.h>
using namespace std;


int longestSubstringWithoutNoRepeat(string &s,int &n){
	int ans = 0 , l = 0;
	unordered_map<char,int>freq;
	for(int r = 0 ; r < n ; r++){
		freq[s[r]]++;
		while(l<r && freq[s[r]]>1){
			freq[s[l]]--;
			l++;
		}
		ans = max(ans,r-l+1);
	}
	return ans;
}

int main(){

	int n;
	cin >> n ;
	string s;
	cin >> s;

	cout << longestSubstringWithoutNoRepeat(s,n);

	
	return  0;
}