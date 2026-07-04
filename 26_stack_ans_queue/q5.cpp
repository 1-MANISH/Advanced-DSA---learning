#include <bits/stdc++.h>
using namespace std;
#define ll long long 

class MinStack {
    stack<pair<ll,ll>>st;
public:
    MinStack() {
        // implement
    }

    void push(ll x) {
        if(st.empty()){
            st.push({x,x});
        }else{
            st.push({x,min(x,getMin())});
        }
    }

    void pop() {
        st.pop();
    }

    ll top() {
        return st.empty()?-1:st.top().first;
    }

    ll getMin() {
        return st.empty()?-1:st.top().second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MinStack st;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll x;
            cin >> x;
            st.push(x);
        } else if (type == 2) {
            st.pop();
        } else if (type == 3) {
            cout << st.top() << "\n";
        } else {
            cout << st.getMin() << "\n";
        }
    }

    return 0;
}