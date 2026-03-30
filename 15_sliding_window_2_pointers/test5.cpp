
/*
Q:
LONGEST SUBARRAY WITH NO DUPLICATES

*/
#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithNoDup(vector<int>&arr,int &n){
    unordered_map<int,int>mp;
    int startIndex = 0 ,endIndex = 0 , maxLen = 0;
    for(int i = 0 ; i < n ; i++){
        if(mp.find(arr[i])!= mp.end() && mp[arr[i]]>=startIndex){
            maxLen = max(maxLen,endIndex-startIndex+1);
            startIndex=mp[arr[i]]+1;
            mp[arr[i]]=i;
        }else{
            mp[arr[i]]=i;
        }
        endIndex=i;
        
    }
    return max(maxLen,endIndex-startIndex+1);

}
int longestSubarrayWithNoDup2(vector<int>&arr,int &n){
    unordered_map<int,int>freq;
    int maxLen = 0 , l = 0;
    for(int r = 0 ; r < n ; r++){
        freq[arr[r]]++;   
        while(l< n && freq[arr[r]]>1){
            freq[arr[l]]--;
            l++;
        }
        maxLen = max(maxLen,r-l+1);
        
    }
    return maxLen;
        

}

int main(){

    int n;
    cin >> n ;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    cout<<longestSubarrayWithNoDup2(arr,n);    

    
    return  0;
}