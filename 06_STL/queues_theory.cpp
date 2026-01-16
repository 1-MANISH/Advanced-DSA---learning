#include<bits/stdc++.h>
using namespace std;


/*

Stack - LIFO
	
	Implementation - 
		Using Array or Linked List

	stack<container or ds>s;

	s.push() -O(1)
	s.pop() -O(1)
	s.top() -O(1)
	s.size() -O(1)
	s.empty() -O(1)
	Travsersal  - O(n)

	stack<int>sTemp(s);

Queue -  FIFO

	Implementation - 
		Using Array or Linked List

	queue<container or nay ds>q;

	q.push() -O(1)
	q.pop() -> front -O(1)
	q.front() -O(1)
	q.size() -O(1)
	q.empty() -O(1)
	Travsersal  - O(n)

	Copy : queue<int>qTemp(q);
*/

void printQueue(queue<int>q){
	cout << "Size = " << q.size() << endl;
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
	cout << "-----\n\n";
}
int main(){

	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	printQueue(q);
	q.pop();
	printQueue(q);






	return 0;
}