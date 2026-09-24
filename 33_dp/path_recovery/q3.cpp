#include <bits/stdc++.h>
using namespace std;
#define ll long long

// C. House Robber I (Print Houses)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/C


const int N = 1e5;
ll dp[N];

vector<int>path;

ll solve(int index,vector<int>&house){

    //base case

    if(index>=house.size()){
        return 0;
    }

    if(dp[index]!=-1) return dp[index];

     // not choose current house
    ll ans1 =  solve(index+1,house);

    // choose current house
    ll ans2 = house[index] + solve(index+2,house);


    ll ans =  max(ans1,ans2);

    return  dp[index] = ans;
}

void recover(int index,vector<int>&house){

    //base case

    if(index>=house.size()){
        return;
    }


    // not choose current house
    ll ans1 =  solve(index+1,house);

    // choose current house
    ll ans2 = house[index] + solve(index+2,house);


    ll ans =  max(ans1,ans2);

    if(ans==ans1){
        recover(index+1,house);
    }else{
        path.push_back(index);
        recover(index+2,house);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>house(n);

    for(int i  = 0 ; i < n ; i++)
        cin >>  house[i];

    memset(dp,-1,sizeof dp);

    cout << solve(0,house) << endl;

    recover(0,house);

    for(auto &ele:path)cout << ele << " ";

    

    return 0;
}

