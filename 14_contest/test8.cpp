#include<bits/stdc++.h>
using namespace std;


int equalsCount(vector<int>&arr,int &n,int &ele){
	int s = 0 , e = n-1 , fo  = -1, lo = -1;
	while(s<=e){
		int m = s+(e-s)/2;
		if(arr[m]==ele){
			fo = m;
			e = m-1;
		}else if(arr[m]<ele){
			s = m+1;
		}else{
			e = m-1;
		}
	}

	if(fo==-1)return 0;

	s = 0 , e = n-1;
	while(s<=e){
		int m = s+(e-s)/2;
		if(arr[m]==ele){
			lo = m;
			s = m+1;
		}else if(arr[m]<ele){
			s = m+1;
		}else{
			e = m-1;
		}
	}
	return lo-fo+1;
}

int lessCount(vector<int>&arr,int &n,int &ele){
	int s = 0 ,  e = n-1 , ans = -1;
	while(s<=e){
		int m = s+(e-s)/2;
		if(arr[m]<ele){
			ans = m;
			s = m+1;
		}else{
			e = m-1;
		}
	}
	return ans==-1 ?0:ans+1;
}
int greatorCount(vector<int>&arr,int &n,int &ele){
	int s = 0 ,  e = n-1 , ans = -1;
	while(s<=e){
		int m = s+(e-s)/2;
		if(arr[m]>ele){
			ans = m;
			e = m-1;
		}else{
			s = m+1;
		}
	}
	return ans==-1 ?0:n-ans;
}

int main(){

	int n ,q ;
	cin >> n  >> q;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	sort(arr.begin(),arr.end());
	while(q--){
		int x ,ele;
		cin >> x >> ele;

		if(x==1){
			cout << equalsCount(arr,n,ele) << endl;
		}else if(x==2){
			cout << lessCount(arr,n,ele) << endl;
		}else if(x==3){
			cout << greatorCount(arr,n,ele) << endl;
		}
	}

	
	return 0;
}