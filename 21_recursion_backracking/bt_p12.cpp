
#include<bits/stdc++.h>
using namespace std;


// Rate in maze -  1(free) / 0(closed) -  DLRU - no repeat

bool isValid(int i,int j,int n, vector<vector<int>>&maze,vector<vector<bool>>&visited){

	if(i>=0 && i< n && j>=0 && j<n && maze[i][j]==1 && !visited[i][j])
		return true;
	else return false;
}

void solver(vector<vector<int>>&maze,int &n,int i,int j,string &output,vector<string>&ans,vector<vector<bool>>&visited){



	if(i==n-1 && j==n-1){
		ans.push_back(output);
		return;
	}

	if(visited[i][j] || maze[i][j]==0){
		return;
	}else{
		visited[i][j]=true;

		// down
		if(isValid(i+1,j,n,maze,visited)){
			output.push_back('D');
			solver(maze,n,i+1,j,output,ans,visited);
			output.pop_back();
		}
			

		// left
		if(isValid(i,j-1,n,maze,visited)){
			output.push_back('L');
			solver(maze,n,i,j-1,output,ans,visited);
			output.pop_back();
		}

		// right
		if(isValid(i,j+1,n,maze,visited)){
			output.push_back('R');
			solver(maze,n,i,j+1,output,ans,visited);
			output.pop_back();
		}

		// up
		if(isValid(i-1,j,n,maze,visited)){
			output.push_back('U');
			solver(maze,n,i-1,j,output,ans,visited);
			output.pop_back();
		}

		//backtrack path
		visited[i][j]=false;
	}
}

int main(){

	int n;
	cin >> n;
	vector<vector<int>>maze(n,vector<int>(n,0));
	for(int i = 0 ; i < n ;i++){
		for(int j = 0 ; j < n ; j++)
			cin >> maze[i][j];
	}
	vector<vector<bool>>visited(n,vector<bool>(n,false));
	string output;
	vector<string>ans;
	solver(maze,n,0,0,output,ans,visited);
	cout << ans.size() << endl;
	for(auto &path:ans)cout << path<<endl;
	
	return 0 ;
}