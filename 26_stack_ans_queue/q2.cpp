#include <bits/stdc++.h>
using namespace std;


unordered_map<char,int> mapping= {
        {'(',1},{')',-1},
        {'[',2},{']',-2},
        {'{',3},{'}',-3},
};

bool isValid(string s)
{
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                if (mapping[s[i]]>0) st.push(mapping[s[i]]);
                else
                {
                    if (st.size() == 0) return false;
                    else if (st.top()+mapping[s[i]]!=0) return false;
                    st.pop();
                }
            }
            return st.size() == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        cout << (isValid(s)?"Yes\n" :"No\n"); 
    }

    return 0;
}



