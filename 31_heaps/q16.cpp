#include <bits/stdc++.h>
using namespace std;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;



class KthLargest {

	MinHeap<int>min_heap;
	int k;
public:

    KthLargest(int k, vector<int>& nums) {
    	this->k=k;
    	for(auto &ele:nums){
    		min_heap.push(ele);
    		if(min_heap.size()>k){
    			min_heap.pop();
    		}
    	}
    }

    int add(int val) {
    	min_heap.push(val);
    	if(min_heap.size()>k)min_heap.pop();
        return min_heap.top();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    KthLargest obj(k, nums);

    int q;
    cin >> q;

    while(q--)
    {
        int val;
        cin >> val;

        cout << obj.add(val) << '\n';
    }

    return 0;
}