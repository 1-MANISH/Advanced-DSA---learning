#include<bits/stdc++.h>
using namespace std;


// Balance parenthesis
// 3
// {[()]}
// {[(])}
// {{[[(())]]}}

bool isBalanced(string &s){

	stack<char>st;
	int n = s.size();
	for(int i = 0 ; i < n ; i++){
		if(s[i]=='{' || s[i]=='[' || s[i]=='('){
			st.push(s[i]);
		}
		else{
			if(st.empty())return false;
			char top=st.top();
			if(s[i]=='}' && top=='{'){st.pop();continue;}
			else if(s[i]==']' && top=='['){st.pop();continue;}
			else if(s[i]==')' && top=='('){st.pop();continue;}
			return false;
		}
	}
	return st.size()==0;
}
// Next Greator Element

// O(N^2)
void printNextGreaters(vector<int>&arr,int &n){
    for(int i = 0 ; i< n ; i++){
      int ele = -1;
      for(int j = i+1;j<n;j++){
        if(arr[i]<arr[j]){
          ele=arr[j];
          break;
        }
      }
      cout << arr[i] << " " << ele << endl;
    }
}

void printNextGreaterUsingStack(vector<int>&arr,int &n){
	vector<int>output(n,-1);
	stack<pair<int,int>>st;
	for(int i = 0 ; i < n ; i++){
		if(st.empty()){
			st.push({arr[i],i});
		}else{
			auto eleP = st.top();
			while(!st.empty() && eleP.first<arr[i]){
				st.pop();
				output[eleP.second]=arr[i];
				if(!st.empty())
					eleP = st.top();
			}
			st.push({arr[i],i});
		}
	}
	for(int i = 0 ; i< n ; i++){
		cout << arr[i] << " "<< output[i] << endl;
	}
}
int main(){

	int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)cin >>arr[i];
    
    printNextGreaterUsingStack(arr,n);

	// int n;
	// cin >> n;
	// while(n--){
	// 	string s;
	// 	cin >> s;
	// 	cout << isBalanced(s) << endl;
	// }

	return 0;
}