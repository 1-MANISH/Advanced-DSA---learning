#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isNumber(char &ch){
        return (ch>='1' && ch<='9');
    }
    bool isChar(char &ch){
        return (ch>='a' && ch<='z');
    }

public:
    string decodeString(string s) {
        stack<char>st;
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            if( s[i] != ']'){
                st.push(s[i]);
            }else{
                string str = "";
                while(!st.empty() && isChar(st.top()) ){
                    str=st.top()+str;
                    st.pop();
                }
                st.pop();
                int k = 0 , mul = 1;
                while(!st.empty() && isNumber(st.top())){
                    k=st.top()*mul+k;
                    mul*=10;
                    st.pop();
                }
                cout << "="<< k <<  "=>" << str << endl;
                while(k--){
                    str+=str;
                }
                ans+=str;
            }
        }
        return ans;
    }
};

int main() {
	string str;
	cin >> str;
    Solution sl;

    cout << sl.decodeString(str) << endl;

}
