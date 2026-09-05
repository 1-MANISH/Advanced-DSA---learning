#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/video-stitching/submissions/2130598858/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        // skipping overlapping 
        sort(clips.begin(),clips.end());
        int endPoint = 0 , count = 0  ,index =  0 , n = clips.size();
        while(index<n){
            int farthest = -1;
            while(index<n and clips[index][0]<=endPoint){
                farthest = max(farthest,clips[index][1]);
                index++;
                // taking best possible
            }
            if(farthest==-1)return -1;// not possible to from [0,t]
            count++;
            if(farthest>=time)return count;// got the answer till this clip only
            endPoint = farthest;// now its time to take another clips to get the answer
           
        }
        if(endPoint<time)return -1;
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vector<vector<int>>clips(n,vector<int>(2));
    for(int i = 0 ; i < n ; i++){
    	cin >>clips[i][0] >> clips[i][1] ;
    }
    Solution sol;
    cout << sol.videoStitching(clips,t);
    

    return 0;
}
