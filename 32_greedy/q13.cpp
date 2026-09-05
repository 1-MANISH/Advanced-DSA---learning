#include <bits/stdc++.h>
using namespace std;

struct Movie{
    int startTime;
    int endTime;
};
 
// maximum number of movies anyone can watch
// https://cses.fi/problemset/task/1629
 
bool compare(Movie &a , Movie &b){
    if(a.endTime==b.endTime){
        return a.startTime<b.startTime;// early start
    }else{
        return a.endTime<b.endTime;// early finsh ko pahle rakho
    }
}
 
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
    
    // based on end time -  increasing order 
    // means movies which can be finish early and start also early
    sort(movies.begin(),movies.end(),compare);
 
    int index = 1 ,  endTime = movies[0].endTime, canWatch = 1 ;
 
    while(index< n){
        if(movies[index].startTime>=endTime){
            endTime = movies[index].endTime;
            canWatch++;
            index++;
        }else{
            //skipping this movies -  to maximize watch
            index++;
        }
    }
    cout << canWatch << endl; 
 
 
    return 0;

}
