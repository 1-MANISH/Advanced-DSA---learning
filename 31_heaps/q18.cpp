#include <bits/stdc++.h>
using namespace std;

// M. Find Median from Data Stream
// https://ai-agentic-whiteboard.vercel.app/
template<typename T>
using MaxHeap = priority_queue<T>;

template<typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

class MedianFinder {
    MinHeap<int>min_heap;
    MaxHeap<int>max_heap;

public:

    MedianFinder() {

    }

    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();

        if(max_heap.size()<min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }

    double findMedian() {

        if(min_heap.size()>=max_heap.size()){
            return 0.5*((double) max_heap.top() + (double) min_heap.top());
        }
        return (double)max_heap.top();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MedianFinder mf;

    cout << fixed << setprecision(5);

    while(Q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x;
            cin >> x;

            mf.addNum(x);
        }
        else
        {
            cout << mf.findMedian() << '\n';
        }
    }

    return 0;
}