#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/car-pooling/

struct Data {
    int location;
    int passengers;// pickup = +num, drop = -num  
};

class Solution {
    static bool compare(Data &a,Data &b){
        if(a.location==b.location){
            return a.passengers<b.passengers;
        }
        return a.location<b.location;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<Data>events;
        for(auto &trip:trips){
            Data d1,d2;
            d1.location=trip[1];
            d1.passengers=trip[0];
            d2.location=trip[2];
            d2.passengers=-trip[0];
            events.push_back(d1);
            events.push_back(d2);
        }
        sort(events.begin(),events.end(),compare);
        int passengers =  0;
        for(auto &event:events){
            passengers+=event.passengers;
            if(passengers>capacity)return false;
        }
        return true;
    }
};



int main() {
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n ,capacity;
    cin >> n >> capacity;
    vector<vector<int>>trips(n,vector<int>(3));
    for(int i = 0 ; i  < n  ;i++)
        cin >> trips[i][0] >> trips[i][1] >> trips[i][2];

    Solution sol;
    cout << (sol.carPooling(trips,capacity)?"true":"false") << endl;

    return 0;
}