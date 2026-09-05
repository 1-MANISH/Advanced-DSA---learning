#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/candy/description/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int>left(n),right(n);
        left[0]=1;
        for(int i = 1 ; i < n ; i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        right[n-1]=1;
        for(int i = n-2 ; i>=0 ; i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }else{
                right[i]=1;
            }
        }

        int ans = 0 ;
        for(int i = 0 ; i < n ;i++){
            ans+=max(left[i],right[i]);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>ratings(n);
    for(int i = 0 ; i < n ; i++){
    	cin >> ratings[i];
    }
    Solution sol;

    cout << sol.candy(ratings);

    

    return 0;
}
