#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/group/4vcXCPx8NY/contest/722152/problem/B
//  Print the Longest Increasing Subsequence



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);

    for(int i = 0 ; i < n  ; i++)
        cin >> arr[i];


    // technique 2
    vector<int>dp(n,1);//// single element always make sub seq
    vector<int>parent(n,-1);

    for(int i = 0 ; i< n ; i++){
        for(int j = i-1 ; j>= 0 ; j--){
            if(arr[j]<arr[i] and 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j]; // we can extend with prev result
                parent[i]=j;// moving to parent
            }
        }
    }


    int idx = max_element(dp.begin(),dp.end()) -dp.begin();
    cout << dp[idx] << endl;

    vector<int>lis;

    while(idx!=-1){
        lis.push_back(arr[idx]);
        idx=parent[idx];
    }
    reverse(lis.begin(),lis.end());
    for(auto &x:lis)cout << x << " ";


    return 0;
}

