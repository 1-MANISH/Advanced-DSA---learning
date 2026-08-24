#include <bits/stdc++.h>
using namespace std;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

//L. Merge K Sorted Arrays

// k pointer technique using heaps
vector<int> mergeSortedArray(vector<vector<int>>&matrix){
    vector<int>output;
    MinHeap<vector<int>>min_heap;//{ele,row,col}

    for(int row = 0 ; row < matrix.size();row++){
        min_heap.push({matrix[row][0],row,0});
    }

    while(!min_heap.empty()){
        auto top =min_heap.top();
        auto element = top[0],row=top[1],column=top[2];
        min_heap.pop();
        output.push_back(element);
        if(column+1<matrix[row].size()){
            min_heap.push({matrix[row][column+1],row,column+1});
        }
    }

    return output;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m ;
    vector<vector<int>>matrix(n,vector<int>(m));

    for(int i  = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> matrix[i][j];
        }
    }


    vector<int>output =mergeSortedArray(matrix);
    for(auto &ele:output)cout << ele << " ";
    

    return 0;
}