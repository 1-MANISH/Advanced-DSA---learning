
#include<bits/stdc++.h>
using namespace std;

class Order{
public:
	int orderId,timestamps,priority;
	Order(int orderId,int timestamps,int priority){
		this->orderId=orderId;
		this->timestamps=timestamps;
		this->priority=priority;
	}
};

bool compare(Order& o1,Order& o2){
	if(o1.priority==o2.priority){
		if(o1.timestamps==o2.timestamps){
			return o1.orderId<o2.orderId;
		}
		else return o1.timestamps<o2.timestamps;
	}
	else return o1.priority>o2.priority;
}

int main(){

	int n ;
	cin >> n;
	vector<Order>orders;
	for(int i = 0 ; i < n ; i++){
		int orderId,timestamps,priority;
		cin >> orderId >> timestamps >> priority;
		orders.push_back(Order(orderId,timestamps,priority));
	}
	sort(orders.begin(),orders.end(),compare);
	for(auto &order:orders){
		cout << order.orderId << " " << order.timestamps << " " << order.priority << endl;
	}
	
	return 0;
}