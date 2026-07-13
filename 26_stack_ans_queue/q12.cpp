#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreater(vector<int>&arr,int &n){
    vector<int>output(n,-1);
    stack<int>st;
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            output[i]=-1;
        }else{
            output[i]=st.top();
        }
        st.push(i);
    }
    return output;
}

void computeStokeSpan(vector<int>&stockPrice,int &n){
    vector<int>prevGreater = previousGreater(stockPrice,n);
    vector<int>output(n,1);
    for(int i = 0 ; i < n ; i++){
        if(prevGreater[i]!=-1){
            output[i] = i-prevGreater[i];
        }else{
            output[i]=i+1;
        }
    }
    for(auto &ele:output)cout << ele << " ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n ; 
    vector<int>stockPrice(n);
    for(int i = 0 ; i < n  ;i++)
        cin >> stockPrice[i];

    computeStokeSpan(stockPrice,n);

  
    return 0;
}

