
#include<bits/stdc++.h>
using namespace std;


int smallest_greater_eq_x(vector<int>&arr,int &n,int &x){
       
        int s = 0 ,e = n-1 , m , ele = -1;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]>=x){
                     ele = arr[m];
                     e = m-1;   
                }else{
                     s = m+1;    
                }
                
        }
        return ele;
       
}


int largest_less_eq_x(vector<int>&arr,int &n,int &x){
       
        int s = 0 ,e = n-1 , m , ele = -1;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]<=x){
                     ele = arr[m];
                     s = m+1;   
                }else{
                     e = m-1;    
                }
                
        }
        return ele;
       
}


int main(){

        int n , q;
        cin >> n >> q;
        vector<int>arr(n);
        for(int i = 0 ;  i < n ; i++)
                cin >> arr[i];
        sort(arr.begin(),arr.end());
        while(q--){
                int x;
                cin >> x ;
                cout <<largest_less_eq_x(arr,n,x)<<endl;
        }
}