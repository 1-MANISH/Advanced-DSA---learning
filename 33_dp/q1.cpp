#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
const int M = 1e9+7;

int dp[N+1];
/*

Fibonacci Term
0 1 1 2 3 5 8


     ONLY REC    DP

N =  functional calls
3 -  3           3
4 -  5           5
5 -  9           7
6 -  15          9
7 -  25          11
8 -  41          13
9 -  61          15
10 - 109         17
20 - 13529       27
30 - 1664079     57

*/



int fib(int n){


    if(n==1 or n==2)return n-1;

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = (fib(n-1)+fib(n-2))%M;

    return dp[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int  i = 0  ; i< n+2 ; i++)
        dp[i] = -1;

    cout <<  fib(n+1) << endl;


    
    

    return 0;
}
