#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1



struct Data{
    int t_period;
    int weight;
};


class Solution {
    
    static bool cmp(Data &a , Data &b){
        if(a.t_period==b.t_period){
            return a.weight<b.weight;
        }
        return a.t_period<b.t_period;
    }
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        vector<Data>events;
        int n = start.size();
        for(int i = 0 ; i < n ;i++){
            Data d1,d2;
            d1.t_period=start[i];
            d1.weight=1;
            d2.t_period=end[i];
            d2.weight=-1;
            events.push_back(d1);
            events.push_back(d2);
        }
        sort(events.begin(),events.end(),cmp);
        int count = 0 , ans = 0 ;
        for(int  i = 0 ; i < 2*n ;  i++){
            count+=events[i].weight;
            ans = max(ans,count);
        }
        return ans;
    }
};


int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n;
    cin >> n;
    vector<int>start(n),end(n);//{startTime,endTime}

    for(int i = 0 ; i< n ; i++)cin >> start[i];
    for(int i = 0 ; i< n ; i++)cin >> end[i]; 

    Solution sol;

    cout << sol.minMeetingRooms(start,end);

    return 0;
}