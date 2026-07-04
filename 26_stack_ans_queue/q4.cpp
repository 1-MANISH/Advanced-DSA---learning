#include <bits/stdc++.h>
using namespace std;

bool isOpening(char & ch)
{
    if (ch == '(' || ch == '[' || ch == '{') return true;
    return false;
}
bool isClosing(char & ch)
{
    if (ch == ')' || ch == ']' || ch == '}') return true;
    return false;
}

int  maxDepth(string &s){
    int mxDepth = 0 , cnt = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(isOpening(s[i])>0)
        {
            cnt++;
        }
        else if(isClosing(s[i]))
        {
            mxDepth = max(mxDepth,cnt);
            cnt--;
        }
    }
    return mxDepth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    cout << maxDepth(s);

    return 0;
}



