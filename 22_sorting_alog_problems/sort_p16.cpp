
#include<bits/stdc++.h>
using namespace std;
int rx,ry;

bool compare(pair<int,int>&cordinate1,pair<int,int>&cordinate2){

	long long int e1  = 0LL+pow(0LL+cordinate1.first-rx,2)+pow(0LL+cordinate1.second-ry,2);
	long long int e2  = 0LL+pow(0LL+cordinate2.first-rx,2)+pow(0LL+cordinate2.second-ry,2);

	if(e1==e2){
		if(cordinate1.first==cordinate2.first)
			return cordinate1.second<cordinate2.second;
		else return cordinate1.first<cordinate2.first;
	}else return e1 < e2;
}

int main(){

	int n ;
	cin >> n >> rx >> ry;
	vector<pair<int,int>>cordinates;
	for(int i = 0  ; i < n ; i++){
		int x,y;
		cin >> x >> y;
		cordinates.push_back({x,y});
	}

	sort(cordinates.begin(),cordinates.end(),compare);
	for(auto &cordinate:cordinates){
		cout <<  cordinate.first << " " << cordinate.second << endl;
	}
	
	return 0;
}