#include <bits/stdc++.h>
using namespace std;


// I. Next Greater Element (Right)
void nextGreater(vector<int>&arr,int &n){

    stack<pair<int,int>>st;//ele,index
    vector<int>output(n,-1);
    for(int i = 0  ; i < n ; i++){
        if(st.empty()){
            st.push({arr[i],i});
        }else{
            if(st.top().first>=arr[i]){
                st.push({arr[i],i});
            }
            else{
                while(!st.empty() && st.top().first<arr[i]){
                    output[st.top().second]=arr[i];
                    st.pop();
                }
                st.push({arr[i],i});
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(output[i]==-1)cout << "X";
        else cout << output[i];
        cout << " ";
    }
}

void nextGreater2(vector<int>&arr,int &n){

    stack<int>st;//index
    vector<int>output(n,-1);
    for(int i = n-1  ; i >= 0 ; i--){
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


    nextGreater2(arr,n);

  
    return 0;
}



