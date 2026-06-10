
#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr,int &s,int &mid,int &e){
   int i = s , j = mid+1 , k =s  , n = mid , m = e;
   vector<int>output;

   while(i<=n && j<=m){
      if(arr[i]<=arr[j]){
         output.push_back(arr[i++]);
      }else{
         output.push_back(arr[j++]);
      }
   }
   while(i<=n ){
      output.push_back(arr[i++]);
   }
   while(j<=m){
     output.push_back(arr[j++]);
   }
    cout << "Merge: ["<< s << " "<< e << "] -> ";
   for(auto &ele:output){
   	arr[k++]=ele;
   	cout << ele << " ";
   }cout << endl;
  

}

void mergeSort(vector<int>&arr,int s,int e){

	if(s<e){
		cout << "Divide: ["<< s << " "<< e << "]\n";
		int m = s+(e-s)/2;

		mergeSort(arr,s,m);
		mergeSort(arr,m+1,e);
		merge(arr,s,m,e);
	}
}

int main(){

	int n ;
	cin >> n ;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    mergeSort(arr,0,n-1);
	
	
	return 0;
}