#include <bits/stdc++.h>
using namespace std;
#define ll long long


void countResult(vector<int>&arr,int &n,int i,ll result, unordered_map<ll,int>&freq){
    if(i>=n){
            freq[result]++;
            return;
    }

    //take +
    countResult(arr,n,i+1,0LL+result+arr[i],freq);

    // take-
    countResult(arr,n,i+1,0LL+result-arr[i],freq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    unordered_map<ll,int>freq;
    countResult(arr,n,1,arr[0],freq);
    cout << freq.size() << endl;   


    return 0;
}