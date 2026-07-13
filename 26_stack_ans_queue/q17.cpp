#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;

	queue<int>q;
	for(int i = 1 ; i <=N ; i++)q.push(i);
	cout << "Discarded cards: ";
	while(q.size()!=1){
		int discard = q.front();
		q.pop();
		int nextFront = q.front();
		q.pop();
		q.push(nextFront);
		cout << discard << " ";
	}
	cout << endl << "Remaining card: " << q.front();
	
	return 0;
}