#include <bits/stdc++.h>
using namespace std;

// E. Subset Sum (Print Subset)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/E
const int N = 1e3+1;
const int W = 1e3+1000;
int dp[N][W];

vector<int>result;

bool solve(int index,int currentSum,int &x,vector<int>&arr){

    // base case

    if(index==arr.size()){
        return currentSum==x;
    }

    if(currentSum>x){
        return false;
    }

    if(dp[index][currentSum]!=-1) return dp[index][currentSum];


    // take it
    bool ans1 = solve(index+1,currentSum+arr[index],x,arr);

    // not take it
    bool ans2 = solve(index+1,currentSum,x,arr);

    return dp[index][currentSum] = ans1 or ans2;
}

void recover(int index,int currentSum,int &x,vector<int>&arr){

    // base case

    if(index==arr.size()){
        return;
    }


    // take it
    bool ans1 = solve(index+1,currentSum+arr[index],x,arr);

    // not take it
    bool ans2 = solve(index+1,currentSum,x,arr);

    bool ans = ans1 or ans2;

    if(ans==ans1 and ans1 and !ans2){
        // take this element in answer - we are considering this element
        result.push_back(index);
        recover(index+1,currentSum+arr[index],x,arr);
    }else{
        recover(index+1,currentSum,x,arr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    memset(dp,-1,sizeof dp);
    bool answer = solve(0,0,x,arr);
    if(answer){
        cout << "YES\n";
        // recover path
        recover(0,0,x,arr);
        for(auto &ele:result) cout << ele << " ";
    }else{
        cout << "NO\n";
    }

    

    return 0;
}

