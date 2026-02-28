
// second largest element
#include<bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    int second_lar=INT_MIN;
	int first_lar=INT_MIN;
	for(int i=0;i<n;i++)
	{
	    if(arr[i]>first_lar)
	    {
	            second_lar=first_lar;
	            first_lar=arr[i];
	            
	    }
	    else if(arr[i]>second_lar && arr[i]!=first_lar)
	    {
	            second_lar=arr[i];
	    }
	         
	}
	return second_lar==INT_MIN ? -1:second_lar;
        
}

int main(){
	 
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0 ; i < n ; i++){
	 	cin >> arr[i];
	} 

	cout << getSecondLargest(arr);

	
	return  0;
}