#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
    Implement only the class below.
*/
class MaxHeap {
    vector<ll>arr;
public:
    MaxHeap() {
    }

    void insert(ll x) {
        arr.push_back(x);
        int index = arr.size()-1;
        int parent_index = (index-1)/2;
        while(parent_index>=0 && arr[index]>arr[parent_index]){
            swap(arr[index],arr[parent_index]);
            index=parent_index;
            parent_index=(index-1)/2;
        }
    }

    void removeMax() {
        if(size()==0)return;
        swap(arr[0],arr[arr.size()-1]);
        arr.pop_back();

        int index = 0 , n = arr.size();
        while(index<n){
            int lc = 2*index+1;
            int rc = 2*index+2;

            if(lc>=n)break;
            int s_index=lc;
            if(rc<n and arr[rc]>arr[s_index])s_index=rc;
            if(arr[index]>=arr[s_index])break;
            swap(arr[index],arr[s_index]);
            index=s_index;
        }
    }

    ll getMax() {
        return arr.size()==0?-1:arr[0];
    }

    ll size() {
        return arr.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MaxHeap hp;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll x;
            cin >> x;
            hp.insert(x);
        }
        else if (type == 2) {
            hp.removeMax();
        }
        else if (type == 3) {
            cout << hp.getMax() << "\n";
        }
        else {
            cout << hp.size() << "\n";
        }
    }

    return 0;
}