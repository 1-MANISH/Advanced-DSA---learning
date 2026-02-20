// selection sort
#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>&arr,int &n){
	for(int i = 0 ; i < n ; i++)cout<< arr[i] << " ";
		cout << ", ";
}

void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0 ; i<= n-2; i++){
            int minIndex = i;
            for(int j = i+1 ;j <=n-1 ; j++){
                if(arr[minIndex]>arr[j])minIndex=j;
            }
            int minSelected = arr[minIndex];
            swap(arr[minIndex],arr[i]);
            cout << "Pass "<<i+1 << ": ";
        	printArr(arr,n);
            cout << "min_selected = "<< minSelected << endl;
            
        }
    }



int main(){
        
        int n ;
        cin >> n ;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)cin >> arr[i];

        selectionSort(arr);	
        	

        
        return  0;
}