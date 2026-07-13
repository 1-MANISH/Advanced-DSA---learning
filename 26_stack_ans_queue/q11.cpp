#include <bits/stdc++.h>
using namespace std;

// next greater
void nextWarmerDay(vector<int>&T,int &n){
    stack<int>st; // element_index
    vector<int>output(n,0);
    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && T[st.top()]<=T[i]){
            st.pop();
        }
        if(st.empty()){
            output[i]=0;
        }else{
            output[i]=st.top()-i;
        }
        st.push(i);
    }
    for(auto &ele:output)cout << ele << " ";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>T(n);
    for(int i = 0 ; i < n ; i++)
        cin >> T[i];
    nextWarmerDay(T,n);

  
    return 0;
}

