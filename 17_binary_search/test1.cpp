#include<bits/stdc++.h>
using namespace std;


bool linearSearch(vector<int>&arr,int &n,int &target){
        for(int i = 0 ; i < n ; i++){
                if(arr[i]==target)return true;
        }
        return false;
}  


bool binarySearch(vector<int>&arr,int &n,int &target){

        int start  = 0 , end = n-1;
        while(start<=end){
                int mid = start+(end-start)/2;
                if(arr[mid]==target)return true;
                else if (arr[mid]<target)start=mid+1;
                else end=mid-1;
        }
        return false;
}  
bool binarySearch2(vector<int>&arr,int &n,int &target){

        int start  = 0 , end = n-1;
        while(end-start>1){
                int mid = start+(end-start)/2;
                if(arr[mid]==target)return true;
                else if (arr[mid]<target)start=mid+1;
                else end=mid-1;
        }
        if(arr[start]==target)return true;
        else if(arr[end]==target)return true;
        return false;
}     


int main(){

        int n , target;
        cin >> n >> target;
        vector<int>arr(n);
        for(int i = 0  ; i < n ; i++)
                cin >> arr[i];

        if(binarySearch2(arr,n,target)){
                cout << "YES\n";
        }else{
                cout << "No\n";
        }

}