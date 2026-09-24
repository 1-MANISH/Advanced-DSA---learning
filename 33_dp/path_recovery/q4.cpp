#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 0/1 Knapsack (print items)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/D

const int N = 1e3+10;
const int W = 1e3+10;
ll dp[N][W];

vector<int>items;


ll solve(int index,int currentWeight,int &w,vector<int>&weight,vector<int>&value){

    // base case
    if(index>=weight.size()){
        return 0;
    }

    if(dp[index][currentWeight]!=-1) return dp[index][currentWeight];

    // take it if possible
    ll ans1 = 0;

    if(currentWeight+weight[index]<=w){
        ans1 = 0LL+value[index] + solve(index+1,currentWeight+weight[index],w,weight,value);
    }

    // not take it
    ll ans2 = solve(index+1,currentWeight,w,weight,value);

    ll ans = max(ans1,ans2);

    return dp[index][currentWeight] =  ans;
}

void recover(int index,int currentWeight,int &w,vector<int>&weight,vector<int>&value){

    // base case
    if(index==weight.size()){
        return ;
    }

    // take it if possible
    ll ans1 = 0;

    if(currentWeight+weight[index]<=w){
        ans1 = 0LL+value[index] + solve(index+1,currentWeight+weight[index],w,weight,value);
    }

    // not take it
    ll ans2 = solve(index+1,currentWeight,w,weight,value);

    ll ans = max(ans1,ans2);

    if(ans==ans1){
        // we have taken this item
        if(currentWeight+weight[index] <= w){
            items.push_back(index);
            recover(index+1,currentWeight+weight[index],w,weight,value);
        }
    }else{
         recover(index+1,currentWeight,w,weight,value);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,w;
    cin >> n >> w;
    vector<int>weight(n),value(n);
    for(int i  = 0 ; i < n ; i++)
        cin >> weight[i];
    for(int i = 0 ; i < n ;  i++)
        cin >> value[i];

    memset(dp,-1,sizeof dp);

    cout << solve(0,0,w,weight,value) << endl;

    recover(0,0,w,weight,value);

    for(auto &ele:items) cout << ele << " ";

    return 0;
}

