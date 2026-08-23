#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // insert -  heapify_up
    void heapify_up(vector<int>&arr,int &i){
        int index=i;
        int parent = (index-1)/2;
        while(parent>=0 && arr[index]>arr[parent]){
            swap(arr[index],arr[parent]);
            index=parent;
            parent=(index-1)/2;
        }
    }
    
    // remove - heapify_down
    void heapify_down(vector<int>&arr,int &n){
        int parent = 0;
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
        for(int index  = 0 ;index < n ; index++){
            heapify_up(arr,index);//log(n)
        }// nlogn
        
        // 2. getting maximum and placing at right postion(max-last)
        // rearrange arr[0] if needed
        for(int index = n-1 ;index > 0 ; index--){
            swap(arr[0],arr[index]);
            heapify_down(arr,index);
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