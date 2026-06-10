
#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr,int &s,int &mid,int &e,int &inversion){
   int i = s , j = mid+1 , k =s  , n = mid , m = e;
   vector<int>output;

   while(i<=n && j<=m){
   		if(i<j && arr[i]>arr[j]){
   			inversion+=1;
   			cout << i << " " << j << " - > (" << arr[i] << " , " << arr[j] << ")" << endl;
   		}

      	if(arr[i]<=arr[j]){
         	output.push_back(arr[i++]);
      	}else{
         	output.push_back(arr[j++]);
        }
    }
    bool flag  = false;
    while(i<=n ){
    	if(!flag){
    		inversion+=(n-s);
    		flag=true;
    	}
    	cout << i << " " << j << " - > (y" << arr[i] << " , " << arr[j] << ")" << endl;
      	output.push_back(arr[i++]);
    }
   	while(j<=m){
     	output.push_back(arr[j++]);
   	}
   	for(auto &ele:output){
   		arr[k++]=ele;
   	}
}

void mergeSort(vector<int>&arr,int s,int e,int &inversion){

	if(s<e){
		int m = s+(e-s)/2;
		mergeSort(arr,s,m,inversion);
		mergeSort(arr,m+1,e,inversion);
		merge(arr,s,m,e,inversion);
	}
}

int main(){

	int n ,inversion = 0;
	cin >> n ;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    mergeSort(arr,0,n-1,inversion);
	cout << inversion << endl;
	return 0;
}