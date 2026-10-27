#include<bits/stdc++.h>

using namespace std;

int main()

{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u,v,p,q;
    cin >> n;
    cin >> u >> v;
    cin >> p >> q;

    if(u==p or u==q){
        cout << u << endl;
    }else{
        cout << v;
    }



    return 0;


}