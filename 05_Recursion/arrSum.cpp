#include <bits/stdc++.h>
using namespace std;

int arrSum(vector<int>&arr,int n){
    if(n <= 0)return 0;
    return arr[n-1]+arrSum(arr,n-1);
}

int digitSum(int n){
    if(n<=0)return 0;
    return (n%10)+digitSum(n/10);
}

int main() {
    
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin>>arr[i];
    cout << arrSum(arr,n)<< endl;

    // cout << n << " digit sum = " << digitSum(n) ;
    
}