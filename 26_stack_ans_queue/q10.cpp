#include <bits/stdc++.h>
using namespace std;

// J. Next Smaller Element's Index
void nextSmalletElementIndex(vector<int>&arr,int &n){

    stack<int>st;
    vector<int>output(n,-1);

    for(int i = n-1 ; i >=0 ; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            output[i]=-1;
        }else{
            output[i]=st.top();
        }
        st.push(i);
    }

    for(int i = 0 ; i < n ; i++){
        if(output[i]==-1)cout << "X";
        else cout << output[i];
        cout << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    nextSmalletElementIndex(arr,n);
  
    return 0;
}

