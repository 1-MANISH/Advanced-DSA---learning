#include <bits/stdc++.h>
using namespace std;


const int REST = 0 ;
const int CONTEST = 1;
const int GYM = 2;
const int CONTEST_GYM = 3;
const int N = 1e5;
int dp[N][5];

string result = "";

int solve(int index ,int PREV_EVENT,vector<int>&events){
	
	// base case
	if(index==events.size()){
		return 0;
	}

	if(dp[index][PREV_EVENT]!=-1) return dp[index][PREV_EVENT];

	// REST -  always choose to rest
	int ans1  = 1 + solve(index+1,REST,events);

	// CONTEST
	int ans2 = events.size()+10;
	if((events[index]==CONTEST or events[index]==CONTEST_GYM )and PREV_EVENT!=CONTEST)
		ans2 = solve(index+1,CONTEST,events);

	// GYM
	int ans3 = events.size()+10;
	if((events[index]==GYM or events[index]==CONTEST_GYM )and PREV_EVENT!=GYM)
		ans3 = solve(index+1,GYM,events);

	return dp[index][PREV_EVENT] = min(ans1,min(ans2,ans3));

	
}

void recover(int index ,int PREV_EVENT,vector<int>&events){
	
	// base case
	if(index==events.size()){
		return;
	}


	// REST -  always choose to rest
	int ans1  = 1 + solve(index+1,REST,events);

	// CONTEST
	int ans2 = events.size()+10;
	if((events[index]==CONTEST or events[index]==CONTEST_GYM )and PREV_EVENT!=CONTEST)
		ans2 = solve(index+1,CONTEST,events);

	// GYM
	int ans3 = events.size()+10;
	if((events[index]==GYM or events[index]==CONTEST_GYM )and PREV_EVENT!=GYM)
		ans3 = solve(index+1,GYM,events);

	int ans = min(ans1,min(ans2,ans3));
	if(ans==ans1){
		result+="R";
		recover(index+1,REST,events);
	}else if(ans==ans2){
		result+="C";
		recover(index+1,CONTEST,events);
	}else{
		result+="G";
		recover(index+1,GYM,events);
	}

	
}




int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n  ;
    cin >> n ;

    vector<int>events(n);

    for(int i = 0  ; i  < n ; i++){
    	cin >> events[i];
    }
    memset(dp,-1,sizeof dp);
    cout << solve(0,REST,events) << endl;
    recover(0,REST,events);
    cout << result;
   
}

// https://myorders.bigrock.in/login