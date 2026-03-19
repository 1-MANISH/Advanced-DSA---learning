#include<bits/stdc++.h>
using namespace std;


int main(){

	int n , l ,r;
	cin >> n >> l >> r;
	string s;
	cin >> s;
	unordered_map<char,vector<int>>mp;
	for(int i = 0 ; i < n ; i++){
		mp[s[i]].push_back(i+1);
	}
	long int count = 0;
	for(auto &ptr:mp){
		int m =  ptr.second.size();
		if(m<=1)continue;
		else{
			int i = 0 ;
			while(i < m){
				int j = ptr.second[i+1] , k  = ptr.second[m-1];
				while(j< m && j<l)j++;
				while(k>=i && k>r)k--;
				if(j<k)count+=k-j+1;
				i++;
			}
		}
	}
	cout << count << endl;
	return  0 ;
}