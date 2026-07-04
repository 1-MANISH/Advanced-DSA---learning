#include <bits/stdc++.h>
using namespace std;



void solve(string &s,int &idx){
    stack<int>st;
    for(int i = 0 ; i  < s.size() ; i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')')
        {
            if(idx==st.top()){
                cout << i ;
                return;
            }
            st.pop();
        }
    }
    cout << -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int idx;
    cin >> s >> idx;
    solve(s,idx);

    return 0;
}



