// inserttion sort
#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>&arr,int &n){
    for(int i = 0 ; i < n ; i++)cout<< arr[i] << " ";
        cout << ", ";
}
void printShiftArr(vector<int>&arr,int &n,int &shift){
    for(int i = 0 ; i < n ; i++){
        if(i==shift){
            cout << arr[i] << " | ";
        }else{
            cout<< arr[i] << " ";
        }
    }cout << ", ";
}

void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1 ;  i<n ; i++){
            int j = i;
            int tempEle = arr[i],shiftCount = 0;
            while(j>0 && tempEle<arr[j-1]){
                arr[j]=arr[j-1];
                j--;
                shiftCount++;
            }
            arr[j]=tempEle;
            cout << "Pass " << i << ": ";
            printArr(arr,n);
            printShiftArr(arr,n,i);
            cout << "shifts = " << shiftCount << endl;

          
        }
}

int main(){
        
        int n ;
        cin >> n ;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)cin >> arr[i];
	
        insertionSort(arr);	
        	

        
        return  0;
}