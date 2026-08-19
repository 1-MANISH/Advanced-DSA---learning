#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// max heap implenetation
// at it th index
// parent = (i-1)/2
// left child = 2*i + 1
// right child = 2*i + 2
// max heap with array

class MaxHeap{
    vector<ll>arr;//[]
public:
    void insert(ll x){
        arr.push_back(x);
        int element_index = arr.size()-1;
        int parent_index  = (element_index-1)/2;
        while(parent_index>=0 && x > arr[parent_index]){
            swap(arr[parent_index],arr[element_index]);
            element_index = parent_index;
            parent_index = (element_index-1)/2;
        }
    }

    ll getMax(){
        return (size()==0) ? LONG_MIN  : arr[0];
    }

    void removeMax(){
        if(size()==0)return;
        swap(arr[0] ,arr[arr.size()-1]);// swap 
        arr.pop_back();// delete last (which is max)
        int element_index=0;// place this ar right position
        int n = arr.size();
        while(element_index<n){
            int l_c_index = 2*element_index+1;
            int r_c_index = 2*element_index+2;

            if(l_c_index>=n)break;
            
            int max_child_index =l_c_index;
            if(r_c_index<n && arr[max_child_index]<arr[r_c_index])
                max_child_index=r_c_index;
            if(arr[element_index]>=arr[max_child_index])break;
            swap(arr[element_index],arr[max_child_index]);
            element_index=max_child_index;
        }
    }

    int size(){
        return arr.size();
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MaxHeap mxheap;
    mxheap.insert(10);
    mxheap.insert(12);
    mxheap.insert(9);
    mxheap.insert(14);
    mxheap.insert(13);


    cout << "Size = "<< mxheap.size() << " Max element = " << mxheap.getMax() << endl;
    mxheap.removeMax();
    cout << "Size = "<< mxheap.size() << " Max element = " << mxheap.getMax() << endl;
    mxheap.removeMax();
    cout << "Size = "<< mxheap.size() << " Max element = " << mxheap.getMax() << endl;
    mxheap.insert(14);
    cout << "Size = "<< mxheap.size() << " Max element = " << mxheap.getMax() << endl;
    mxheap.removeMax();
    mxheap.removeMax();
    mxheap.removeMax();
    mxheap.removeMax();
    cout << "Size = "<< mxheap.size() << " Max element = " << mxheap.getMax() << endl;
    mxheap.insert(14);
    cout << "Size = "<< mxheap.size() << " Max element = " << mxheap.getMax() << endl;
    return 0;
}