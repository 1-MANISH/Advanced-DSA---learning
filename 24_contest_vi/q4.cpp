#include <bits/stdc++.h>
using namespace std;
#define ll long long


void generatePossibleSequence(int k,int rem,vector<int>&output,vector<vector<int>>&ans){
    if(rem==0){
        ans.push_back(output);
        return;
    }

    //take from choices
    for(int i = 1 ; i <= 6 ; i++){
        if(i<=rem){
            output.push_back(i);
            generatePossibleSequence(k,rem-i,output,ans);
            output.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<int>output;
    vector<vector<int>>ans;
    generatePossibleSequence(k,k,output,ans);

    for(auto &p:ans){
        for(auto &ele:p)cout << ele <<  " ";
        cout << endl;
    }



    return 0;
}