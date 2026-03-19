#include<bits/stdc++.h>
using namespace std;



int main(){

	int q;
	cin >> q;
	unordered_map<int,int>mp;

	while(q--){
		int n ,x;
		cin >> n;
		if(n==3){
			cout << mp.size() << endl;
		}else{
			int x;
			cin >> x;
			if(n==1)mp[x]++;
			else if(n==2){
				auto it = mp.find(x);
				if(it!=mp.end()){
					cout << (*it).first << " " << mp[x] << endl;
					if(mp[x]==1){
						mp.erase(it);
					}
					else mp[x]--;
				}	
			}else{
				cout << (mp[x]==0 ? "NO":"YES") << endl;
			}
		}
	}


	
	return  0;
}