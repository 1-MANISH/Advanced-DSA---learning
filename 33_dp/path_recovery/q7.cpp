#include <bits/stdc++.h>
using namespace std;

// G. Edit Distance (Print Operations)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/G

//  convert A ---> B (s---> t)
const int N = 1e3;
int dp[N][N];

class Operation{
public:
    string opr;
    int pos;
    char ch;

    Operation(string opr,int pos=-1,char ch='1'){
        this->opr = opr;
        this->pos = pos;
        this->ch = ch;
    }
};

vector<Operation*>result;

int solve(int i,int j,string &s,string &t){

    // base case

    // number of rem in t string
    if(j==t.size()){
        // delete all S(A) string character to make A==B(S==T)
        return s.size()-i;
    }


    if(i==s.size()){
        // insert characters into string S(A) to make A==B
        return t.size()-j;
    }

    if(dp[i][j]!=-1) return dp[i][j];


    // both char are equal
    int ans = INT_MAX ;
    if(s[i]==t[j]){
        ans = solve(i+1,j+1,s,t);
    }else{
        // replace ,delete or insert

        // replace this char - in s replace this char 
        int ans1  = 1 + solve(i+1,j+1,s,t);

        // removing s ith char 
        int ans2 = 1 + solve(i+1,j,s,t);

        // inserting new char in s 
        int ans3 = 1 + solve(i,j+1,s,t);

        ans =min(ans1,min(ans2,ans3));

    }
    return  dp[i][j] = ans;
}


void recover(int i,int j,string &s,string &t){

    // base case

    // number of rem in t string
    if(j==t.size()){
        // delete all S(A) string character to make A==B(S==T)
        for(int index=i ;index<s.size();index++){
            result.push_back(new Operation("DELETE",index-1));
        }
        return ;
    }


    if(i==s.size()){
        // insert characters into string S(A) to make A==B
        for(int index=j ,k  = 0  ;index<t.size();index++,k++){
            result.push_back(new Operation("INSERT",s.size()+k,t[index]));
        }
        return;
    }


    // both char are equal
    int ans = INT_MAX ;
    if(s[i]==t[j]){
        ans = solve(i+1,j+1,s,t);
        recover(i+1,j+1,s,t);
    }else{
        // replace ,delete or insert

        // replace this char - in s replace this char 
        int ans1  = 1 + solve(i+1,j+1,s,t);

        // removing s ith char 
        int ans2 = 1 + solve(i+1,j,s,t);

        // inserting new char in s 
        int ans3 = 1 + solve(i,j+1,s,t);

        ans =min(ans1,min(ans2,ans3));

        if(ans==ans1){
            result.push_back(new Operation("REPLACE",i,t[j]));
            recover(i+1,j+1,s,t);
        }else if(ans==ans2){
            result.push_back(new Operation("DELETE",i));
            recover(i+1,j,s,t);
        }else{
            result.push_back(new Operation("INSERT",i,t[j]));
            recover(i,j+1,s,t);
        }

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;

    cin >> s >> t;

    memset(dp,-1,sizeof dp);

    cout << solve(0,0,s,t) << endl;
    
    recover(0,0,s,t);

    for(auto &ele:result){
        if(ele->opr=="DELETE"){
            cout << ele->opr << " " << ele->pos << endl;
        }else{
            cout << ele->opr << " " << ele->pos << " "<< ele->ch<< endl;
        }
    }

    return 0;
}

