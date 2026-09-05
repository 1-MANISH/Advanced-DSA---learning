#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/non-overlapping-intervals/description/

#include<bits/stdc++.h>
class Solution {

    // end point ke basis par sorting  - increasing order
    bool static compare(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }else{
            return a[1]<b[1];
        }
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // need to maximize(take as possible ) -intervals to be there

        sort(intervals.begin(),intervals.end(),compare);

        int index=1 ,  endPoint = intervals[0][1] ,  canBeThere=1 ,  n = intervals.size();

        while(index<n){
            if(intervals[index][0]>=endPoint){
                endPoint = intervals[index][1];//current interval - can be there
                index++;
                canBeThere++;
            }else{
                index++;
            }
        }

        return n - canBeThere;// number of removed intervals

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>>intervals(n,vector<int>(2));
    for(int i = 0 ; i < n ; i++){
    	cin >>intervals[i][0] >> intervals[i][1];
    }

    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals);

    

    return 0;
}
