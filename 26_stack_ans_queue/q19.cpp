#include<bits/stdc++.h>
using namespace std;


int main(){
	vector<string>allowedDigits;
	for(int i = 0 ; i < 10 ; i++){
		int digit;
		cin >> digit;
		if(digit)allowedDigits.push_back(to_string(i)); 
	}

	int N , cnt=1;
	cin >> N;
	queue<queue<string>>q;
	queue<string>firstSet;
	for(auto digit:allowedDigits){
		if(digit!="0")firstSet.push({digit});
	}
	q.push(firstSet);
	while(!q.empty()){
		queue<string> p_elements=q.front();
		queue<string> t_elements = q.front();
		q.pop();
		
		queue<string>output;
		while(!p_elements.empty()){
			for(auto &digit:allowedDigits){
				string temp = p_elements.front()+digit;
				output.push(temp);
			}
			p_elements.pop();
		}
		q.push(output);
		if(cnt>N)break;

		while(!t_elements.empty()){
			if(cnt>N)break;
			cout << t_elements.front()<<endl;
			t_elements.pop();
			cnt++;
		}
		
	}
	
	return 0;
}