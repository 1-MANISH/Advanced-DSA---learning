
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isPossible(vector<int>&stalls,int &n,int &m, int &k){
        int count = 1;
        int start_pos  = stalls[0];
        for(int i  = 1 ; i < n ; i++){
                int d = stalls[i]-start_pos;
                if(d>=m){
                        count++;
                        start_pos=stalls[i];
                }
        }
        return count >=k;
}


signed main(){

        int n ,k;
        cin >> n >> k;
        vector<int>stalls(n);
        for(int i = 0 ; i < n  ; i++)
                cin >> stalls[i];
;       sort(stalls.begin(),stalls.end());
        int s = 0,e = stalls[n-1]-stalls[0] ,ans = -1;
 
        while(s<=e){
                int m = s+((e-s)>>1);
                if(isPossible(stalls,n,m,k)){
                        ans = m;
                        s = m+1;
                }else{
                        e = m-1;
                }
        }
        cout << ans;

        return 0;
}