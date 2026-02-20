// bubble sort
#include<bits/stdc++.h>
using namespace std;


void printArr(vector<int>&arr,int &n){
    for(int i = 0 ; i < n ; i++)cout<< arr[i] << " ";
    cout << ", ";
}


void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ; i<=n-2; i ++){
            int swap_count = 0;
            for(int j = 0 ; j<=n-i-2;j++){
                if(arr[j]>arr[j+1]){
                    swap_count++;
                    swap(arr[j],arr[j+1]);
                }
            }
           
            cout << "Pass "<< i+1 << ": ";
            printArr(arr,n);
            cout << "swaps = " << swap_count << endl;
            if(!swap_count)break;
        }
}

int main(){
        
        int n ;
        cin >> n ;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)cin >> arr[i];
	
        bubbleSort(arr);	
        
        // printArr(arr,n);	

        
        return  0;
}