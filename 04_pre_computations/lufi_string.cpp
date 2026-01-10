#include <bits/stdc++.h>
using namespace std;

/*

t<=10
1<=n,q<=10^5
1<=l,r<=n
'a'<=s[i]<='z'

1 based indexing


Brute Force : O(N+Q*N) = O(N^2)==> 10^10



*/



int main() {
	int t;
	cin >> t;

	while(t--)
	{
		int n,q;
		string s;
		cin >> n >> q;
		cin >> s;
		while(q--){
			int l,r,flag=0;
			cin >> l >> r;
			unordered_map<char,int>mp;
			for(int i  = l-1 ; i <r ; i++){
				mp[s[i]]++;
			}
			for(auto ele:mp){
				if(ele.second & 1){
					flag++;
				}
				if(flag>1){
					break;
				}
			}
			cout << (flag<=1 ? "YES":"NO") <<endl;
		}
	}	
}