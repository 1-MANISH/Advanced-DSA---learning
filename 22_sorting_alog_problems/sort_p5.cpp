
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void countPairs(vector<int>& arr, int s, int mid, int e,ll &rPair ) {
        int i = s, j = mid + 1;
        int count = 0;
        while (i <= mid) {
            while (j <= e && arr[i] > 2LL * arr[j])
                j++;
            rPair += j - mid - 1;
            i++;
        }
}

void merge(vector<int>&arr,int &s,int &mid,int &e,ll &rPair){

	int i = s , j = mid+1 , k=s , n = mid , m = e;
	vector<int>output;//storing in decreasing order
	while(i <=n && j <= m ){
		if(arr[i]<=arr[j])
			output.push_back(arr[i++]);
		else
			output.push_back(arr[j++]);
	}
	while(i<=n ){
		output.push_back(arr[i++]);
	}
	while(j<=m ){
		output.push_back(arr[j++]);
	}
	for(auto &ele:output){//making sorted-original array
		arr[k++]=ele;
	}

}

void mergeSort(vector<int>&arr,int s,int e,ll &rPair){
	if(s<e){
		int m = s+(e-s)/2;
		mergeSort(arr,s,m,rPair);
		mergeSort(arr,m+1,e,rPair);
		countPairs(arr,s,m,e,rPair);
		merge(arr,s,m,e,rPair);
	}
}

int main(){

	int n ;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)cin >> arr[i];
	ll rPair = 0 ;
	mergeSort(arr,0,n-1,rPair);
	cout << rPair << endl;
	return 0;
}