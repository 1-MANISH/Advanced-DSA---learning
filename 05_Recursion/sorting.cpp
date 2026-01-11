#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int &s,int &m ,int &e){
        int len1 = e-s+1;
        int tempArr[len1];

        // merge + sorted -into a new array
        int i = s , j = m+1,index=0;
        while(i<=m && j<=e){
            if(arr[i]>arr[j]){
                tempArr[index++]=arr[j++];
            }else{
                tempArr[index++]=arr[i++];
            }
        }
        while(i<=m){
            tempArr[index++]=arr[i++];
        }
        while(j<=e){
            tempArr[index++]=arr[j++];
        }
        index=0;
        // now copy into original one
        for(int  i = s ; i<=e ; i++){
            arr[i]=tempArr[index++];
        }

    }
void mergeSort(vector<int>& arr, int l, int r) {
            // code here
        int m = l+(r-l)/2;
        if(l<r){
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
    }
}


int main() {
    
	int n ;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin>> arr[i];

    for(int i = 0 ; i < n ; i++)cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr,0,n-1);
    for(int i = 0 ; i < n ; i++)cout << arr[i] << " ";
    return 0;

}




