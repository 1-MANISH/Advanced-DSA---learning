    
#include<bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int>&nums,int &n,int i ,vector<int>temp,vector<vector<int>>&output){
        if(i==n){
            output.push_back(temp);
            return;
        }

        // selected
        temp.push_back(nums[i]);
        generateSubsets(nums,n,i+1,temp,output);
        temp.pop_back();

        // not selected
        generateSubsets(nums,n,i+1,temp,output);
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>output;
        vector<int>temp;
        int n =nums.size();
        generateSubsets(nums,n,0,temp,output);
        return output;
}

int main(){

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >> arr[i];


    vector<vector<int>>output = subsets(arr);

    for(auto &subset:output){
        for(auto &ele:subset)cout << ele << " ";
            cout << endl;
    }
    return 0;
}