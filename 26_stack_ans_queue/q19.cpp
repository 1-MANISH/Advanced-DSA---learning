#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	vector<int>allowedDigits;
	for(int i = 0 ; i < 10 ; i++){
		int digit;
		cin >> digit;
		if(digit)
		allowedDigits.push_back(i); 
	}

	int N , cnt=0;
	cin >> N;
	queue<ll>q;
	q.push(0);
	while(!q.empty()){
		ll element = q.front();
		q.pop();
		for(auto &digit:allowedDigits){
			ll newElement = element*10+digit;
			if(newElement>0)
				q.push(newElement);
		}
		if(cnt==0){
			cnt++;
			continue;
		}
		if(cnt>N)break;
		if(cnt>=1 && cnt <= N && element>0){
			cout << element << endl;
			cnt++;
		}
		
	}
	
	return 0;
}