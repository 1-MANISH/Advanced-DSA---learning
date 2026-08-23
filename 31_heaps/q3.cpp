#include <bits/stdc++.h>
using namespace std;

// 347. Top K Frequent Elements
struct Data{
    int value,count;
};

struct CompareData{
    bool operator()(const Data &a,const Data &b){
        return a.count>b.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto &num:nums)freq[num]++;
        priority_queue<Data,vector<Data>,CompareData>minHeap;
        for(auto [value,count]:freq){
            minHeap.push({value,count});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int>answer;
        while(!minHeap.empty()){
            answer.push_back(minHeap.top().value);
            minHeap.pop();
        }
        return answer;
    }
};

int main() {

    bool cmp =[](const Data &a,const Data &b){
        return a.count>b.count;
    };
    priority_queue<Data,vector<Data>,CompareData>minHeap;

    minHeap.push({2,4});
    minHeap.push({12,3});
    minHeap.push({5,6});
    minHeap.push({3,1});
    minHeap.push({17,8});

    while(!minHeap.empty()){
        auto element = minHeap.top();
        cout << element.value  << "  - > " << element.count << endl;
        minHeap.pop();
    }
    return 0;
}