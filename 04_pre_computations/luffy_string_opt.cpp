#include <bits/stdc++.h>
using namespace std;

/*

t<=10
1<=n,q<=10^5
1<=l,r<=n
'a'<=s[i]<='z'

1 based indexing


Brute Force : O(N+Q*N) = O(N^2)==> 10^10

OPtimized

*/

const int N = 1e5+10;
vector<vector<int>>hashed(N,vector<int>(26,0));

int main() {
	int t;
	cin >> t;

	while(t--)
	{
		// for each test cases 
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < 26 ; j++){
				hashed[i][j]=0;
			}
		}
		int n,q;
		string s;
		cin >> n >> q;
		cin >> s;
		for(int i = 0 ; i < n ; i++){
			int colIndex = s[i]-'a';
			hashed[i+1][colIndex]++;
		}
		// calculate prefix Sum
		for(int i = 2 ; i <= n ; i++){
			for(int j = 0 ; j <26 ; j++){
				hashed[i][j]+=hashed[i-1][j];
			}
		}

		while(q--){
			int l,r,oddCounts=0;
			cin >> l >> r;
			for(int i = 0 ; i  < 26 ; i++){
				int count = hashed[r][i]-hashed[l-1][i];
				if(count&1)oddCounts++;
				if(oddCounts>1){
					break;
				} 
			}
			cout << (oddCounts<=1 ? "YES":"NO") <<endl;
		}

	}	
}