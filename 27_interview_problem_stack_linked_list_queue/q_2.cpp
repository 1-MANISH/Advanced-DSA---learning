#include <bits/stdc++.h>
using namespace std;

// nlogn solution
class SolutionUsingPriorityQueue {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        priority_queue<pair<int,int>>maxHeap;
        for(int i = 0 ; i< k ; i++){
            maxHeap.push({nums[i],i});
        }
        output.push_back(maxHeap.top().first);
        for(int i = k ; i< nums.size() ; i++){
            // remove index<i-k+1;
            while(!maxHeap.empty() && maxHeap.top().second<i-k+1)maxHeap.pop();
            maxHeap.push({nums[i],i});
            output.push_back(maxHeap.top().first);
        }
        return output;
    }
};

// o(n) solution
class SolutionUsingDeque {
private:
    void addElementToDeque(deque<pair<int, int>>&dq, int& element,int &index) {
        // removing unneccery
        while(!dq.empty() && dq.back().first <= element)dq.pop_back();
        while(!dq.empty() && dq.front().first <= element)dq.pop_front();
        // adding - making decreasing queue -{back_max,front_min}
        if(dq.empty()) dq.push_back({element, index});
        else if(dq.back().first<element)dq.push_back({element,index});
        else dq.push_front({element,index});
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<pair<int, int>> dq; // back maximum and front minimum
        for (int i = 0; i < k; i++) {
           addElementToDeque(dq,nums[i],i);
        }
        output.push_back(dq.back().first);
        for (int i = k; i < nums.size(); i++) {
            // remove index<i-k+1 
            while (!dq.empty() && dq.front().second < i - k + 1 )dq.pop_front();
            while (!dq.empty() &&dq.back().second < i - k + 1 )dq.pop_back();
            // add current
            addElementToDeque(dq,nums[i],i);
            output.push_back(dq.back().first);
        }
        return output;
    }
};

// o(n) solution using - aggregate queue
// MAX STACK + queue with 2 stack
class AggregateQueue{
    public:
    stack<pair<int,int>>inStack,outStack;//{ele,tillNowMax}

    AggregateQueue(){};
    // o(1)
    void push(int element){
        if(inStack.empty())inStack.push({element,element});
        else inStack.push({element,max(element,inStack.top().second)});
    }
    // Amortized -> avergae -O(1)
    void pop(){
        if(outStack.empty()){
            while(!inStack.empty()){
                if(outStack.empty())outStack.push({inStack.top().first,inStack.top().first});
                else outStack.push({inStack.top().first,max(inStack.top().first,outStack.top().second)});//{ele,max(ele,oldMax)}
                inStack.pop();
            }
        }
        outStack.pop();// unneccerry removal - [i-k+1,i]- removing before wala
    }
    //o(1)
    int getMax(){
        if(inStack.empty())return outStack.top().second;
        if(outStack.empty())return inStack.top().second;
        return max(inStack.top().second,outStack.top().second);
    }

};

class SolutionUsingAggregateQueue {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        AggregateQueue sQueue;
        for(int i = 0 ; i< k ; i++) sQueue.push(nums[i]);
        output.push_back(sQueue.getMax());
        for(int i = k ; i < nums.size(); i++){
            sQueue.push(nums[i]);// add - new one
            sQueue.pop();// remove un-neeccessery
            output.push_back(sQueue.getMax());// getting window max
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
    vector<int>output = d.maxSlidingWindow(arr,k);
    for(auto &ele:output) cout << ele << " ";


    return 0;
}