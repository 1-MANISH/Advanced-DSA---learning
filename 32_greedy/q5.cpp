#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/attend-all-meetings/1
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

class Solution2 {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        
        for(int i=1; i< arr.size() ; i++){
            int s1 = arr[i-1][0];
            int e1 = arr[i-1][1];
            int s2 = arr[i][0];
            int e2 = arr[i][1];
            
            if(max(s1,s2)<min(e1,e2))return false;
        }
        return true;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n;
    cin >> n;
    vector<vector<int>>meetings(n,vector<int>(2));//{startTime,endTime}

    for(int i = 0 ; i< n ; i++)cin >> meetings[i][0];
    for(int i = 0 ; i< n ; i++)cin >> meetings[i][1]; 

    Solution2 sol;

    cout << (sol.canAttend(meetings)?"true":"false") << endl;

    return 0;
}