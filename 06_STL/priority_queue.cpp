#include<bits/stdc++.h>
using namespace std;


/*
pq.push(ele) -log(n)
pq.pop()-log(n)
pq.top()-log(1)
pq.size()-log(1)
pq.empty()-log(1)
pq.swap()
*/

void printMaxHeap(priority_queue<int>pq){
	while(!pq.empty()){
		cout << pq.top()<< endl;
		pq.pop();
	}cout << "------\n\n";
}
void printMinHeap(priority_queue<int,vector<int>,greater<int>>minHeap){
	while(!minHeap.empty()){
		cout << minHeap.top()<< endl;
		minHeap.pop();
	}cout << "------\n\n";
}


int main(){

	// max heap (by default)
	priority_queue<int>pq;
	pq.push(10);
	pq.push(20);
	pq.push(15);
	pq.push(8);

	cout << pq.top() << endl;

	printMaxHeap(pq);

	// min heap
	priority_queue<int,vector<int>,greater<int>>minHeap;

	minHeap.push(5);
	minHeap.push(6);
	minHeap.push(3);
	minHeap.push(7);

	cout << minHeap.top() << endl;
	printMinHeap(minHeap);

	return 0;
}