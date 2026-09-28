#include <bits/stdc++.h>
using namespace std;


const int NONE = 4;
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

	int ans = INT_MAX;

	if(events[index] == REST){
		ans = 1 + solve(index+1,events[index],events);
	}else{
		// CONTEST/ REST
		int ans1 = INT_MAX;
		if(events[index]==CONTEST and PREV_EVENT!=CONTEST )
			ans1 = solve(index+1,CONTEST,events);
		else if(events[index]==CONTEST)
			ans1 = 1 + solve(index+1,REST,events);

		// GYM/REST
		int ans2 = INT_MAX;
		if(events[index]==GYM and PREV_EVENT!=GYM)
			ans2 = solve(index+1,GYM,events);
		else if(events[index]==GYM)
			ans2 = 1 + solve(index+1,REST,events);

		// CONTEST_OR_GYM
		int ans3 = INT_MAX;
		if(events[index] == CONTEST_GYM)
		{
			if(PREV_EVENT==CONTEST){
				ans3 = solve(index+1,GYM,events);
			}
			else{
				ans3 = solve(index+1,CONTEST,events);
			}
		}
		ans = min(ans1,min(ans2,ans3));
	}
	return dp[index][PREV_EVENT]= ans;
}

void recover(int index ,int PREV_EVENT,vector<int>&events){
	
	// base case
	if(index==events.size()){
		return ;
	}

	int ans = INT_MAX;

	if(events[index] == REST){
		ans = 1 + solve(index+1,REST,events);
		result+="R";
		recover(index+1,REST,events);
	}else{
		// CONTEST/ REST
		int ans1 = INT_MAX;
		if(events[index]==CONTEST and PREV_EVENT!=CONTEST )
			ans1 = solve(index+1,CONTEST,events);
		else if(events[index]==CONTEST)
			ans1 = 1 + solve(index+1,REST,events);

		// GYM/REST
		int ans2 = INT_MAX;
		if(events[index]==GYM and PREV_EVENT!=GYM)
			ans2 = solve(index+1,GYM,events);
		else if(events[index]==GYM)
			ans2 = 1 + solve(index+1,REST,events);

		// CONTEST_OR_GYM
		int ans3 = INT_MAX;
		if(events[index] == CONTEST_GYM)
		{
			if(PREV_EVENT==CONTEST)
				ans3 = solve(index+1,GYM,events);
			else
				ans3 = solve(index+1,CONTEST,events);
		}

		ans = min(ans1,min(ans2,ans3));

		if(ans==ans1){
			if(events[index]==CONTEST and PREV_EVENT!=CONTEST ){
				result+="C";
				recover(index+1,CONTEST,events);
			}
			else {
				result+="R";
				recover(index+1,REST,events);
			}
		}else if(ans==ans2){
			if(events[index]==GYM and PREV_EVENT!=GYM){
				result+="G";
				recover(index+1,GYM,events);
			}
			else{
				result+="R";
				recover(index+1,REST,events);
			}
		}else{
			if(events[index] == CONTEST_GYM)
			{
				if(PREV_EVENT==CONTEST){
					result+="G";
					recover(index+1,GYM,events);
				}
				else{
					result+="C";
					recover(index+1,CONTEST,events);
				}
			}
		}
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
    cout << solve(0,NONE,events) << endl;
    recover(0,NONE,events);
    cout << result << endl;
}