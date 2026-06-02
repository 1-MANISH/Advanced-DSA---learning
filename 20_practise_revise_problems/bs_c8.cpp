
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&board,int &n,long long int &m,int &k){
	long long int currentBoardLength = board[0] ;
	int p_count = 1 ;
	for(int i = 1 ; i < n  ; i++){
		if(currentBoardLength+board[i]<=m){
			currentBoardLength+=board[i];
		}else{
			p_count++;
			currentBoardLength = board[i];
			if(currentBoardLength>m)return false;
		}
		if(p_count>k)return false;
	}
	return p_count==k;
}

int main(){

	int n,k;
	cin >> n >> k;
	vector<int>board(n);
	long long int mn = 0 , mx = 0 , ans ;
	for(int i = 0 ; i < n ; i++){
		cin >> board[i];
		mx+=board[i];
	}
	mn = *(max_element(board.begin(),board.end()));
	while(mn<=mx){
		long long int m = mn+(mx-mn)/2;
		if(isPossible(board,n,m,k)){
			ans=m;
			mx=m-1;
		}else{
			mn=m+1;
		}
	}
	cout << ans << endl;



	return 0;
}