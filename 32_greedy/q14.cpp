#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

struct Job{
    int deadline;
    int profit;
};

class Solution {
    
    bool static compare(Job &a,Job &b){
        if(a.deadline==b.deadline){
            return a.profit>b.profit;
        }else{
            return a.deadline<b.deadline;
        }
    }

  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        MinHeap<int>minHeap;
        int  n = deadline.size();
        vector<Job>jobs;
        for(int i =  0 ; i < n ; i++){
            Job job;
            job.deadline = deadline[i];
            job.profit = profit[i];
            jobs.push_back(job);
        }

        // based on deadline means early finsh + greater profit
        sort(jobs.begin(),jobs.end(),compare);

        for(int i = 0 ; i < n ; i++){
            // if we affort to watch movies than watch it
            if(minHeap.size()<jobs[i].deadline){
                minHeap.push(jobs[i].profit);
            }
            else if(minHeap.top()<jobs[i].profit){// if getting greater profit so - remove less profit
                minHeap.pop();
                minHeap.push(jobs[i].profit);
            }
        }
        
        int profitSum=0 , numOfJobPicked = minHeap.size();
        while(!minHeap.empty()){
            profitSum+=minHeap.top();
            minHeap.pop();
        }
        
        return {numOfJobPicked,profitSum};
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>deadlines(n),profits(n);
    for(int i = 0 ; i  < n ;i++){
        cin >> deadlines[i] >> profits[i];
    }

    Solution sol;

    vector<int>output= sol.jobSequencing(deadlines,profits);

    cout << output[0] << " "<< output[1];
    

    

    return 0;
}
