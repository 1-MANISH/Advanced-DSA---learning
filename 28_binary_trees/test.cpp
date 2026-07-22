#include <bits/stdc++.h>
using namespace std;

void copyied(vector<vector<int>>&mat,int &N,int &M,vector<vector<int>>&copy){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){
             copy[i][j] = mat[i][j] ;
        }
    }
}

bool isValid(int &x,int &y ,int &N,int &M){
    if(x>=0 && x<N && y>=0 && y<M)return true;
    else return false;
}

void update(vector<vector<int>>&mat,int &N,int &M,vector<vector<int>>&copy){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){
            int arrX[8] = {+0,-1,-1,-1,+0,+1,+1,+1};
            int arrY[8] = {-1,-1,+0,+1,+1,+1,+0,-1};
            int mx = mat[i][j];
            for(int k = 0 ; k < 8 ; k++){
                int x=i+arrX[k],y=j+arrY[k];
                if(isValid(x,y,N,M)){
                    mx=max(mx,copy[x][y]);
                }
            }
            mat[i][j]=mx;
        }
    }
    copyied(mat,N,M,copy);
}

bool isEqual(vector<vector<int>>&mat,int &N,int &M){
    int x=mat[0][0];
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){
            if(i==0 && j==0)continue;
            if( x!= mat[i][j])return false;;
        }
    }
    return true;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>>mat(N,vector<int>(M));
        vector<vector<int>>copy(N,vector<int>(M));
        for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < M ; j++){
                cin >> mat[i][j];
                copy[i][j]=mat[i][j];
            }
        }
        int hours = 0 ;
        while(!isEqual(mat,N,M)){
            hours++;
            update(mat,N,M,copy);
        }
        cout << hours << endl;
        
    }

    return 0;
}