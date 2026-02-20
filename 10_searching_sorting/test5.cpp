#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>&arr,int n){
	for(int i = 0 ; i < n ; i++)cout<< arr[i] << " ";
}

vector<int> mergeArr(vector<int>&a,vector<int>&b){
	int n = a.size(),m = b.size();
	vector<int>arr(n+m,0);
    int i = 0  , j = 0 , k = 0 ;
    while(i<n && j<m ){
        if(a[i]<=b[j]){
        	arr[k++]=a[i++];
        }
       else{
          arr[k++]=b[j++];
        }
    }
    while(i<n )
        arr[k++]=a[i++];
    while(j<m )
        arr[k++]=b[j++];    
    return arr;   

}
int main(){

	int n , m ;
	cin >> n >> m;
	vector<int>a(n);
	vector<int>b(m);
	for(int i = 0 ; i < n ; i++)cin >> a[i];
	for(int i = 0 ; i < m ; i++)cin >> b[i];	

	vector<int>arr = mergeArr(a,b);
	printArr(arr,n+m);	

	return 0;
}