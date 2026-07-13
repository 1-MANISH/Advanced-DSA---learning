#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//M. maximum Rectangle 

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
ll largestRectangleOptimalInHistogram(vector<int>&bars,int &n){
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

ll maxRectangle(vector<vector<int>>&matrix,int &n,int &m){
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans,largestRectangleOptimalInHistogram(matrix[i],m));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m;
    cin >> n >> m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i = 0 ; i < n  ; i++){
       for(int j = 0 ; j < m ; j++){
            char ch ;
            cin >> ch;
            matrix[i][j] = ch-'0';
       }
    }
    for(int i = 0  ; i < n  ; i++){
        for(int j = 0 ;j < m ; j++){
            if(i!=0){
                if(matrix[i][j]==0)
                    matrix[i][j]=0;
                else
                    matrix[i][j] = matrix[i-1][j]+matrix[i][j];
            }
        }
    }
    cout << 1LL*maxRectangle(matrix,n,m);

  
    return 0;
}

