#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // remove - heapify_down
    void heapify_down(vector<int>&arr,int index,int &n){
        int parent = index;
        while(parent<n){
            int l_c = 2*parent + 1;
            int r_c = 2*parent + 2;
            int c_index = l_c;
            if(l_c >= n)break;
            if(r_c < n && arr[c_index]<arr[r_c])c_index=r_c;
            if(arr[parent] >= arr[c_index])break;
            swap(arr[parent],arr[c_index]);
            parent=c_index;
        }
    }
    
    void heapSort(vector<int>& arr) {

        //1. create a heap - intial heap
        int n = arr.size() ;
        for(int index  = n-1 ;index >= 0; index--){
            heapify_down(arr,index,n);
        }
        
        // 2. getting maximum and placing at right postion(max-last)
        // rearrange arr[0] if needed
        for(int index = n-1 ;index > 0 ; index--){
            swap(arr[0],arr[index]);
            heapify_down(arr,0,index);
        }
    }
};

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;



int main(){

	return 0;
}