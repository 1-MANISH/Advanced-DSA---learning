#include <bits/stdc++.h>
using namespace std;

// SLIDING WINDOW OR
// o(n) solution using - aggregate queue
// MAX STACK + queue with 2 stack
class AggregateQueue{
    public:
    stack<pair<int,int>>inStack,outStack;//{ele,orTillNowMax}

    AggregateQueue(){};
    // o(1)
    void push(int element){
        if(inStack.empty())inStack.push({element,element});
        else inStack.push({element,element|inStack.top().second});
    }
    // Amortized -> avergae -O(1)
    void pop(){
        if(outStack.empty()){
            while(!inStack.empty()){
                if(outStack.empty())outStack.push({inStack.top().first,inStack.top().first});
                else outStack.push({inStack.top().first,inStack.top().first|outStack.top().second});//{ele,ele|oldOr}
                inStack.pop();
            }
        }
        outStack.pop();// unneccerry removal - [i-k+1,i]- removing before wala
    }
    //o(1)
    int getOR(){
        if(inStack.empty())return outStack.top().second;
        if(outStack.empty())return inStack.top().second;
        return inStack.top().second|outStack.top().second;
    }

};

class SolutionUsingAggregateQueue {
public:
    vector<int> orSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        AggregateQueue sQueue;
        for(int i = 0 ; i< k ; i++) sQueue.push(nums[i]);
        output.push_back(sQueue.getOR());
        for(int i = k ; i < nums.size(); i++){
            sQueue.push(nums[i]);// add - new one
            sQueue.pop();// remove un-neeccessery
            output.push_back(sQueue.getOR());// getting window max
        }
        return output;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    SolutionUsingAggregateQueue d ;
    vector<int>output = d.orSlidingWindow(arr,k);
    for(auto &ele:output) cout << ele << " ";


    return 0;
}