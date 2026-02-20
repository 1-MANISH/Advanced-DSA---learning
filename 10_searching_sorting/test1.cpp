// binary search
#include<bits/stdc++.h>
using namespace std;

string binarySearch(vector<string>&arr,int &n,string &target){
        int start = 0 , end = n-1;
        while(start<=end){
                int mid = start+(end-start)/2;
                if(arr[mid]==target){
                        return "YES";
                }else if(arr[mid]<target){
                        start=mid+1;
                }else{
                        end=mid-1;
                }
        }
        return "NO";
}


int main(){
        
        int n ;
        cin >> n ;
        vector<string>arr(n);
        string target;
        for(int i = 0 ; i < n ; i++)cin >> arr[i];
        cin >> target;
        cout << binarySearch(arr,n,target);


        
        return  0;
}