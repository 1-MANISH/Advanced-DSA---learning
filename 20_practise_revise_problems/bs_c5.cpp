
#include<bits/stdc++.h>
using namespace std;


int between_x_y(vector<int>&arr,int &n,int &x,int &y){
       
        if(x>y)return 0;
        int s = 0 ,e = n-1 , m , index = -1,index2=-1;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]>=x){
                     index = m;
                     e = m-1;   
                }else{
                     s = m+1;    
                }
                
        }
        
        if(index==-1)return 0;
        s= 0 , e = n-1 ;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]<=y){
                     index2 = m;
                     s = m+1;   
                }else{
                     e = m-1;    
                }
                
        }
        if(index2==-1)return 0;
        return index2-index+1;
}

int main(){

        int n , q;
        cin >> n >> q;
        vector<int>arr(n);
        for(int i = 0 ;  i < n ; i++)
                cin >> arr[i];
        sort(arr.begin(),arr.end());
        while(q--){
                int x,y;
                cin >> x >>y;
                cout <<between_x_y(arr,n,x,y)<<endl;
        }
}