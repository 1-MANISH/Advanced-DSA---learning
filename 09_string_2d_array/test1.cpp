#include<bits/stdc++.h>
using namespace std;

void take2DArrayInput(vector<vector<int>>&arr,int &n,int &m){
        for(int i = 0 ; i< n ; ++i){
                for(int j = 0 ; j< m ; ++j){
                        cin >> arr[i][j];
                }
        }
}
void printBoundary(vector<vector<int>>&arr,int &n,int &m){
        int flag=true;
        int rs = 0 ,re = n-1,cs = 0 ,ce=m-1;

        while(flag){
                for(int col=cs;col<=ce;col++){
                        cout<<arr[rs][col]<<" ";
                }rs++;
                if(rs>re || cs>ce)break;
                for(int row=rs;row<=re;row++){
                        cout<<arr[row][ce]<<" ";
                }
                ce--;
                if(rs>re || cs>ce)break;
                for(int col=ce;col>=cs;col--){
                        cout<<arr[re][col]<<" ";
                }
                re--;
                if(rs>re || cs>ce)break;
                for(int row=re;row>=rs;row--){
                        cout<<arr[row][cs]<<" ";
                }
                cs++;
                if(rs>re || cs>ce)break;
                flag=false;
        }
}


int main(){
	
        int n,m;
        cin>>n>>m;
        vector<vector<int>>arr(n,vector<int>(m,0));

        take2DArrayInput(arr,n,m);
        printBoundary(arr,n,m);



	return  0;
}