
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&book,int &n,long long int &m,int &k){
        long long int currentPages = 0 ;
        int s_count = 1 ;
        for(int i = 0 ; i < n  ; i++){
                if(currentPages+book[i]<=m){
                        currentPages+=book[i];
                }else{
                        s_count++;
                        currentPages = book[i];
                        if(currentPages>m || s_count>k)return false;
                }
        }
        return s_count<=k;
}

int main(){

        int n,k;
        cin >> n >> k;
        vector<int>book(n);
        long long int mn = 0 , mx = 0 , ans = -1 ;
        for(int i = 0 ; i < n ; i++){
                cin >> book[i];
                mx+=book[i];
        }
        if(k>n){
                cout << -1 << endl;
                return 0;
        }
        mn = 0;
        while(mn<=mx){
                long long int m = mn+(mx-mn)/2;
                if(isPossible(book,n,m,k)){
                        ans=m;
                        mx=m-1;
                }else{
                        mn=m+1;
                }
        }
        cout << ans << endl;



        return 0;
}