#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//M. Largest Rectangle in Histogram
// brute force
ll largestRectangle(vector<int>&bars,int &n){
    ll ans = 0;
    for(int i = 0; i < n ; i++){
        int w = 1;
        int h = bars[i];
        int j = i-1;//left expansion
        while(j>=0 && bars[j]>=h){
            w++;
            j--;
        }
        j = i+1;//right expansion
        while(j<n && bars[j]>=h){
            w++;
            j++;
        }
        ans = max(ans,1LL*h*w); 
    }
    return ans;
}

vector<int> prevSmaller(vector<int>&arr,int &n){
    vector<int>output(n,-1);
    stack<int>st;
    for(int i = 0 ; i < n ; i++){
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
    return output;
}

vector<int> nextSmaller(vector<int>&arr,int &n){
    vector<int>output(n,n);
    stack<int>st;
    for(int i = n-1 ; i >= 0 ; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            output[i]=n;
        }else{
            output[i]=st.top();
        }
        st.push(i);
    }
    return output;
}
// optimal
ll largestRectangleOptimal(vector<int>&bars,int &n){
    ll ans = 0;
    vector<int>pSmall = prevSmaller(bars,n);
    vector<int>nSmall = nextSmaller(bars,n);
    for(int i = 0; i < n ; i++){
        ll h = bars[i];
        ll w = nSmall[i]-pSmall[i]-1;
        ll currentAns = w*h;
        ans = max(ans,currentAns); 
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>bars(n);
    for(int i = 0 ; i < n  ; i++){
        cin >> bars[i];
    }

    cout << 1LL*largestRectangleOptimal(bars,n);

  
    return 0;
}

