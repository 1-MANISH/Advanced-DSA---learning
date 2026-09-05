#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Movie>movies;
    for(int i = 0 ; i < n ; i++){
    	Movie m;
    	cin >> m.startTime >> m.endTime;
    	movies.push_back(m);
    }

    

    return 0;
}
