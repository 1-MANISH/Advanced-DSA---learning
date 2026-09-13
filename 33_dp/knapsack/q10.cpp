#include <bits/stdc++.h>
using namespace std;


// J. Unbounded Knapsack
// https://codeforces.com/group/4vcXCPx8NY/contest/715177/problem/J
/*


1≤n≤1000
1≤W≤1000

1≤val[i]≤100

1≤wt[i]≤100


*/
int** dp;

int maxProfitUnbound(int index,int currentWeight,int &capacity,int &n,vector<int>&weight,vector<int>&cost){

    if(index>=n){
        return 0;
    }

    if(dp[index][currentWeight]!=-1){
        return dp[index][currentWeight];
    }

    // take it
    int a1 = 0;
    if(currentWeight+weight[index]<=capacity){
        // index -  we can take again if possible (same item again)
        a1 = cost[index]+maxProfitUnbound(index,currentWeight+weight[index],capacity,n,weight,cost);
    }


    // not take it
    int a2 = maxProfitUnbound(index+1,currentWeight,capacity,n,weight,cost);

    return dp[index][currentWeight]= max(a1,a2);
}
    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , capacity ;
    cin >> n >> capacity;

    vector<int>cost(n),weight(n);

    for(int i = 0  ; i < n ; i++){
        cin >> cost[i];
    }
    for(int i = 0  ; i < n ; i++){
        cin >> weight[i];
    }

    dp = new int*[n+1];
    for(int i = 0 ; i <=n;i++){
        dp[i] = new int[capacity+1];
    }
    for(int i = 0 ; i <=n;i++){
        for(int j = 0 ; j <= capacity;j++){
            dp[i][j]=-1;
        }
    }


    cout << maxProfitUnbound(0,0,capacity,n,weight,cost);


    return 0;

}