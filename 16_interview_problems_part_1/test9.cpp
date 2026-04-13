/*
Q:
D - Count Intervals
*/
#include<bits/stdc++.h>
using namespace std;

long long int countInterveral(vector<int>&arr,int &n,long long int &k) {

    int l = 0;
    long long int count = 0 , currentSum = 0 ;
    for(int r = 0 ; r < n   ; r++){
        currentSum+=arr[r];
        while(l<r && currentSum==k){
             if(currentSum==k)count++;
            currentSum-=arr[l];
            l++;
        }
        if(currentSum==k)count++;
    }
    return count;
}

int main(){

	int n ;
    long long int k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0 ;  i < n ; i++) cin >> arr[i];

    cout << countInterveral(arr,n,k) << endl;

	return  0;
}