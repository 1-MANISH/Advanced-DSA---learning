#include <bits/stdc++.h>
using namespace std;

void removeAdjacent(string &s){
    stack<char>st;
    for(int i=0 ; i < s.size() ; i++){
        if(st.empty()){
            st.push(s[i]);
        }else{
            if(st.top()==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    string tp="";
    while(!st.empty()){
       tp+=st.top();
       st.pop();
    }
    reverse(tp.begin(),tp.end());
    cout << tp ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    removeAdjacent(s);

    return 0;
}



