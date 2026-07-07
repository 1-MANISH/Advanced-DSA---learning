#include <bits/stdc++.h>
using namespace std;

// I. Next Greater Element (Left)

void nextGreater(vector<int>&arr,int &n){

    stack<int>st;//index
    vector<int>output(n,-1);
    for(int i = 0  ; i < n ; i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            output[i]=-1;
        }else{
            output[i]=arr[st.top()];
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


    nextGreater(arr,n);

  
    return 0;
}

