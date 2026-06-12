
#include<bits/stdc++.h>
using namespace std;

class Flight{
public:
	int flightNumber;
	short departureTime;
	string flightName;

	Flight(int flightNumber,short departureTime,string flightName){
		this->flightNumber=flightNumber;
		this->departureTime=departureTime;
		this->flightName=flightName;
	}
};

bool compare(Flight &f1,Flight& f2){

	if(f1.departureTime==f2.departureTime){
		return f1.flightNumber<f2.flightNumber;
	}
	return f1.departureTime<f2.departureTime;
}

int main(){

	int n ;
	cin >> n;
	vector<Flight>flights;
	for(int i = 0 ; i < n ; i++){
		int flightNumber;
		short departureTime;
		string flightName;
		cin >> flightNumber >> departureTime >> flightName;
		flights.push_back(Flight(flightNumber,departureTime,flightName));

	}
	sort(flights.begin(),flights.end(),compare);
	for(auto &flight:flights){
		cout << flight.flightNumber << " "<< flight.departureTime << " "<< flight.flightName << endl;
	}
	
	return 0;
}