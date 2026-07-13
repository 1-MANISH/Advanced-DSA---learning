#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	ll N , cnt = 0;
	cin >> N;
	queue<ll>q;
	q.push(0);
	while(!q.empty()){
		ll element = q.front();
		q.pop();
		if(cnt==N){
			cout << element << endl;
			break;
		}
		cnt++;
		ll a = element*10+1 , b = element*10+2;
		q.push(a);
		q.push(b);
	}
	
	
	return 0;
}