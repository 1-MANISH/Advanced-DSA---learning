
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a,vector<int>&b,vector<int>&output){
   int i = 0 , j = 0 , k = 0 , n = a.size() , m =  b.size();

   while(i<n && j<m){
      if(a[i]<=b[j]){
         output[k++]=a[i++];
      }else{
         output[k++]=b[j++];
      }
   }
   while(i<n ){
      output[k++]=a[i++];
   }
   while(j<m){
      output[k++]=b[j++];
   }
}


int main(){

	int n  , m;
	cin >> n >> m;
   vector<int>a(n),b(m) ,output(n+m);

   for(int i = 0 ; i < n ; i++)cin >> a[i];
   for(int i = 0 ; i < m ; i++)cin >> b[i];
   
   merge(a,b,output);

   for(auto &ele:output)cout << ele << " ";
   
	
	return 0;
}