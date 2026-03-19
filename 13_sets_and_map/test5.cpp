#include<bits/stdc++.h>
using namespace std;



int main(){

	int q;
	cin >> q;

	map<int,int>ms;

	while(q--){
		int n ,x;
		cin >> n;
		if(n==3){
			cout << ms.size() << endl;
		}else{
			int x;
			cin >> x;
			if(n==1)ms[x]++;
			else if(n==2){
				auto it = ms.find(x);
				if(it!=ms.end())
					ms.erase(x);
			}else{
				auto it = ms.find(x);
				cout << (it==ms.end() ? "NO":"YES") << endl;
			}
		}
	}


	
	return  0;
}