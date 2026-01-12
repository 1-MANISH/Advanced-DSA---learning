#include <bits/stdc++.h>
using namespace std;

/*

TC : O(N^2)
SC : O(1)
*/
void selectionSort(vector<int>&arr,int n){
    for(int i = 0 ; i <= n-2  ; i++){
        int minIndex = i;
        for(int j = i+1 ; j < n ; j++){
            if(arr[minIndex]>arr[j])minIndex=j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

/*

TC : O(N^2)
SC : O(N)
*/
void recursiveSelectionSort(vector<int>&arr,int index,int &n){

    if(index==n-1)return;

    int minIndex = index;

    for(int i = index+1 ; i< n ; i++){
        if(arr[minIndex]>arr[i])minIndex=i;
    }
    swap(arr[minIndex],arr[index]);
    recursiveSelectionSort(arr,index+1,n);
}

void merge(vector<int>&arr,int &start,int &mid,int &end){

    int len = end-start+1;
    int* tempArr = new int[len];

    //merge them
    int i = start , j =mid+1 , k = 0;
    while(i<=mid && j <=end){
        if(arr[i]>arr[j]){
            tempArr[k++]=arr[j++];
        }else{
            tempArr[k++]=arr[i++];
        }
    }
    while(i<=mid ){
        tempArr[k++]=arr[i++];
    }
    while(j <=end){
        tempArr[k++]=arr[j++];
    }

    // copy to original
    for(int index = start ,k  = 0 ; index <=end;index++,k++)arr[index]=tempArr[k];
    delete[] tempArr;
  

}
void mergeSort(vector<int>&arr,int start,int end){
    if(start<end){
        int mid = start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int main() {
    
	int n ;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin>> arr[i];

    for(int i = 0 ; i < n ; i++)cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr,0,n-1);
    for(int i = 0 ; i < n ; i++)cout << arr[i] << " ";
    cout << endl;
   

}




