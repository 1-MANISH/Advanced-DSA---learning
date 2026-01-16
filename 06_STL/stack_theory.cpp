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

void printStack(stack<int>s){
	cout << "Size = " << s.size() << endl;
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	cout << "-----\n\n";
}
int main(){

	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	printStack(s);
	s.pop();
	printStack(s);

	printStack(s);


	return 0;
}