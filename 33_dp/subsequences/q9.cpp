#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/717252/problem/G
// G. Shortest Common Supersequence Length

const int N = 5e2;
int dp[N][N];

int solve(int i,int j,string &s,string &t){

    //base case
    if(i==s.size()){
        return t.size()-j; // rem of t
    }
    if(j==t.size()){
        return s.size()-i;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int ans = 0 ;
    // if both char equals means need to take it
    if(s[i]==t[j]){
        ans = 1 + solve(i+1,j+1,s,t);
    }
    else{
        // take it from s
        int ans1 = 1  + solve(i+1,j,s,t);

        // take it from t
        int ans2 = 1 + solve(i,j+1,s,t);

        ans = min(ans1,ans2);// as shorted supersequen building
    }

    return dp[i][j] =  ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    cin >> s >> t;
    memset(dp,-1,sizeof dp);
    cout << solve(0,0,s,t);

    return 0;
}

/*
https://www.naukrigulf.com/
https://www.gulftalent.com/
https://uae.dubizzle.com/jobs/
https://secure.indeed.com/auth?co=AE&hl=en_AE&jsContinue=https%3A%2F%2Fonboarding.indeed.com%2Fonboarding%3Fhl%3Den%26co%3DAE%26continue%3Dhttps%253A%252F%252Fae.indeed.com%252F%253Fjson%253D1%2526passedCtk%253D1k2v2h3hbhc0m801%26from%3Dhp-accounted-focus
https://builder.aws.com/build/workshops?tab=discover
*/