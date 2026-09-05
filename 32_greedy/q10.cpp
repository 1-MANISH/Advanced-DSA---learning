#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows_needed = 0 ;
        sort(points.begin(),points.end());
        // based on start point - increasing order
        int start = points[0][0] ,  end = points[0][1] ,currentStart,currentEnd;
        int index = 1 , n = points.size();
        while(index<n){
            currentStart = points[index][0] ,  currentEnd = points[index][1];
            if(start<=currentStart && currentStart<=end){
                  start=max(start,currentStart);
                  end=min(end,currentEnd);
                  // skipping intersecting intervals -means with one arrow
                  // we can burst this with previous arrow
            }else{
                arrows_needed++; 
                start=currentStart;
                end=currentEnd;
            }
            index++;
        }
        return arrows_needed+1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>>points(n,vector<int>(2));
    for(int i = 0 ;  i < n ; i++){
        cin >> points[i][0] >> points[i][1];
    }

    Solution sol;
    cout << sol.findMinArrowShots(points);
   

    return 0;
}
