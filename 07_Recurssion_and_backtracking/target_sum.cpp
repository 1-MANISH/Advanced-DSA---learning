#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&arr,int i,int currentSum ,int &target,int &n,vector<int>&temp,vector<vector<int>>&output){
        
        if(i==n ){
            return;
        }

        for(int j = i  ; j < n ; j++){
            if(currentSum==target){
                output.push_back(temp);
                break;
            }
            if(currentSum>target){
                break;
            }
            temp.push_back(arr[j]);
            helper(arr,j,currentSum+arr[j],target,n,temp,output);
            temp.pop_back();
        }
        
}
vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        
        sort(arr.begin(),arr.end());
        vector<vector<int>>output;
        vector<int>temp;
        int n = arr.size();
        helper(arr,0,0,target,n,temp,output);
        return output;
}
int main(){

    int n ,target;
    cin >> n >> target;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    vector<vector<int>>output = targetSumComb(arr,target);

    for(auto &ele:output){
        for(auto &subEle:ele)cout << subEle << " ";
            cout << endl;
    }



    return 0;
}