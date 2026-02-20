// insertion vs selection sort
#include<bits/stdc++.h>
using namespace std;


int selectionSortWork(vector<int> arr) {
        int n = arr.size() , countSwaps=0;
        for(int i = 0 ; i<= n-2; i++){
            int minIndex = i;
            for(int j = i+1 ;j <=n-1 ; j++){
                if(arr[minIndex]>arr[j])minIndex=j;
            }
            if(minIndex!=i)countSwaps++;
            swap(arr[minIndex],arr[i]);   
        }
        return countSwaps;
}

int insertionSortWork(vector<int> arr) {
        int n = arr.size() ,shiftCounts = 0;
        for(int i = 1 ;  i<n ; i++){
            int j = i;
            int tempEle = arr[i];
            while(j>0 && tempEle<arr[j-1]){
                arr[j]=arr[j-1];
                j--;
                shiftCounts++;
            }
            arr[j]=tempEle;
        }
    return shiftCounts;
}


int main(){
        
        int t;
        cin >> t;
        while(t--){
            int n ;
            cin >> n ;
            vector<int>arr(n);
            for(int i = 0 ; i < n ; i++)cin >> arr[i];

            int sw = selectionSortWork(arr);
            int iw = insertionSortWork(arr);

            if(sw==iw){
                cout<< "Tie\n";
            }else if(sw<iw){
                cout << "Selection Sort\n";
            }else{
                cout << "Insertion Sort\n";
            }

        }

        return  0;
}