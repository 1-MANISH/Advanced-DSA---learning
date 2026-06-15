#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int>&arr,int &s,int &mid,int &e){
    int i = s , j = mid+1, n = mid, m =e , k = s;
    vector<int>output;
    while(i<=n && j<=m){
        if(arr[i]<=arr[j])output.push_back(arr[i++]);
        else output.push_back(arr[j++]);
    }
    while(i<=n ){
        output.push_back(arr[i++]); 
    }
    while(j<=m){
        output.push_back(arr[j++]);
    }
    for(auto &ele:output)
        arr[k++]=ele;

}

void countDominantPair(vector<int>&arr,int &s,int &mid,int &e,ll& dPair){
    int i = s , j  = mid+1 , n = mid , m = e ;
    for(int low = i ; low <= n ; low++){
        while(j<=m && arr[low]>3LL*arr[j]){
           j++;   
        }
        dPair+=j-mid-1; 
    }
}

void mergeSort(vector<int>&arr,int s,int e,ll &dPair){
    if(s<e){
        int m = s+(e-s)/2;
        mergeSort(arr,s,m,dPair);
        mergeSort(arr,m+1,e,dPair);
        countDominantPair(arr,s,m,e,dPair);
        merge(arr,s,m,e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    ll dPair = 0 ;
    mergeSort(arr,0,n-1,dPair);
    cout << dPair << endl;    

    return 0;
}