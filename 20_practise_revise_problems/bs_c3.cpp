
#include<bits/stdc++.h>
using namespace std;


void print_num_occ(vector<int>&arr,int &n,int &x){
       
        int s = 0 ,e = n-1 , m , f_o=-1,l_o=-1;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]==x){
                     f_o = m;
                     e = m-1;   
                }
                else if(arr[m]<x)s=m+1;
                else e = m-1;
        }
        if(f_o==-1){
                cout << 0 << endl;
                return;
        }
        s = 0 , e  = n-1;
        while(s<=e){
                m = (s+e)>>1;
                if(arr[m]==x){
                     l_o = m;
                     s = m+1;   
                }
                else if(arr[m]<x)s=m+1;
                else e = m-1;
        }
        cout <<  l_o-f_o+1 << endl;

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
                cin >> x;
                print_num_occ(arr,n,x);
        }
}