#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int s1 = intervals[0][0] ,  e1 = intervals[0][1] , index = 1, n = intervals.size();
        vector<vector<int>>output;
        while(index<n){
            int s2 = intervals[index][0] , e2 = intervals[index][1];
            // overlap 
            if(max(s1,s2)<=min(e1,e2)){
                e1 = max(e1,e2);
            }else{
                output.push_back({s1,e1});
                s1=intervals[index][0];
                e1=intervals[index][1];
            }
            index++;
        }
        output.push_back({s1,e1});
        return output;
    }
};

int main() {
       ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n;
    cin >> n;
    vector<vector<int>>intervals(n,vector<int>(2,0));
    for(int i = 0 ; i < n ;i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution sol;
    vector<vector<int>>output = sol.merge(intervals);
    cout << output.size() << endl;
    for(auto &interval:output){
        cout <<interval[0] << " " << interval[1] << endl;
    }

    return 0;
}