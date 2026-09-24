#include <bits/stdc++.h>
using namespace std;

// G. Edit Distance (Print Operations)
// https://codeforces.com/group/4vcXCPx8NY/contest/718431/problem/G

const int N = 1e3;
int dp[N][N];
int deleted  = 0 ;

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
    // number of rem in any string
    if(i==s.size())return t.size()-j;

    if(j==t.size())return s.size()-i;

    if(dp[i][j]!=-1)return dp[i][j];


    // both char are equal
    int ans = INT_MAX ;
    if(s[i]==t[j]){
        ans = solve(i+1,j+1,s,t);
    }else{
        // replace ,delete or insert
        // replace this char - either j or i wala to each other
        int ans1  = 1 + solve(i+1,j+1,s,t);

        // removing s ith char -  insert at jth in t
        int ans2 = 1 + solve(i+1,j,s,t);

        // removing t jth char - insety at ith in s
        int ans3 = 1 + solve(i,j+1,s,t);

        ans = min(ans1,min(ans2,ans3));

    }
    return dp[i][j] = ans;
}

void recover(int i,int j,string &s,string &t){

    // base case
    // number of rem in any string
    if(i==s.size()){
        for(int index=j ; index < t.size() ; index++){
             result.push_back(new Operation("DELETE",index-deleted));
        }
        return;
    }

    if(j==t.size()){
        for(int index=i ; index < s.size() ; index++){
             result.push_back(new Operation("DELETE",index-deleted));
        }
        return;
    }

    // both char are equal
    int ans = INT_MAX ;
    if(s[i]==t[j]){
        ans = solve(i+1,j+1,s,t);
        recover(i+1,j+1,s,t); // as no operation needed
    }else{
        // replace ,delete or insert
        // replace this char - either i or j
        int ans1  = 1 + solve(i+1,j+1,s,t);

        // removing s ith char -  insert at jth in t
        int ans2 = 1 + solve(i+1,j,s,t);

        // removing t jth char - insety at ith in s
        int ans3 = 1 + solve(i,j+1,s,t);

        ans = min(ans1,min(ans2,ans3));

        if(ans==ans1){
            result.push_back(new Operation("REPLACE",i,s[i]));
            recover(i+1,j+1,s,t);
        }else if(ans2){
            result.push_back(new Operation("DELETE",i-deleted));
            deleted++;
            recover(i+1,j,s,t);
        }else{
            result.push_back(new Operation("DELETE",j-deleted));
            deleted++;
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
        if(ele->opr=="REPLACE"){
            cout << ele->opr << " " << ele->pos << " " << ele->ch << endl;
        }else{
            cout << ele->opr << " " << ele->pos << endl; 
        }
    }
    

    return 0;
}

