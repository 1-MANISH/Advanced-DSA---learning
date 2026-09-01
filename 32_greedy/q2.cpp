#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/boats-to-save-people/


int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0 , j = people.size()-1 , count = 0 ;
        while(i<j){
            int currentPairWeight=people[i]+people[j];
            if(currentPairWeight<=limit){
                count++;
                i++;
                j--;
            }else{
                count++;
                j--;
            }
        }
        if(i==j)count++;
        return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ,limit;
    cin >> n >> limit;
    vector<int>people(n);
    for(int i = 0 ; i  < n ; i++)cin >> people[i];

    cout << numRescueBoats(people,limit);

    return 0;
}