
#include<bits/stdc++.h>
using namespace std;


int b_s(vector<int>&arr,int &n,int &x){
        int s = 0 ,e = n-1 , m;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]==x)return m+1;
                else if(arr[m]<x)e=m-1;
                else s = m+1;
        }
        return  -1;
}

int main(){

        int n , q;
        cin >> n >> q;
        vector<int>arr(n);
        for(int i = 0 ;  i < n ; i++)
                cin >> arr[i];

        while(q--){
                int x;
                cin >> x;
                cout << b_s(arr,n,x) << endl;
        }
}