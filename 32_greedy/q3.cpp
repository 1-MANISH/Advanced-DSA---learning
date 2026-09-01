#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

struct Data {
    int weight;
    double profitPerWeightUnit;
};


bool compare(Data& a,Data &b){
    return a.profitPerWeightUnit>b.profitPerWeightUnit;
}
class Solution {
    public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Data>arr;
        for (int i = 0 ; i < n ; i++) {
            Data d;
            d.weight = wt[i];
            d.profitPerWeightUnit = ((double)val[i]/wt[i]);
            arr.push_back(d);
        }
        sort(arr.begin(),arr.end(),compare);
        int remainingQuantity = capacity , index = 0 ;
        double profit = 0 ;
        while(index<n){
            if(remainingQuantity-arr[index].weight>0){
                remainingQuantity-=arr[index].weight;
                profit+=(double)arr[index].weight*arr[index].profitPerWeightUnit;
            }else{
                profit+=(double)remainingQuantity*arr[index].profitPerWeightUnit;
                break;
            }
            index++;
        }
        return profit;
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w;
    cin >> n >> w;
    vector<int>val(n),weight(n);
    for(int i = 0 ; i < n ; i++)
        cin >> val[i] >> weight[i];

    Solution sol;

    double ans =sol.fractionalKnapsack(val,weight,w);
    cout <<fixed << setprecision(6) << ans ;

    return 0;
}