#include<bits/stdc++.h>
using namespace std;

/*

STL
1)  Containers -
		sequentials - vector,stack,queue,pair(not a container - a class)
		oredered - map,set,multi_map,mutli_set
		unordered - unordered_map, unordered_set
2)  Iterators -
		pointers to memery address of containers
		begin()
		end()
		vector<int>::iterator it;
		short way to write
3)  Algorithms -
		count
		lower_bound
		upper_bound
		reverse
		sort(conparator)
		max_element
		min_element
		count
		find
		next_permatations
		prev_permutations
		accumalate

4 ) Functors -
		Classes which can act like functions
*/

/*

n<=10^5


*/

int minNumberOfKeyRequired(string &s,int &n){
	unordered_map<char,int>mp;
	int minKeys = 0;
	for(int i = 0 ; i < 2*n-2 ; ++i){
		if(i&1){
			char ch = 'a'+s[i]-'A' ;
			if(mp[ch]>0)mp[ch]--;
			else minKeys++;
		}else{
			mp[s[i]]++;
		}
		
	}
	return minKeys;
}

int main(){


	// int Q;
    // cin >> Q;
    // unordered_map<string, int>nameToMarks;
    // while(Q--){
        
    //     int type, marks;
    //     string name;
    //     cin >> type;
    //     if(type==1){
    //         cin >> name >> marks;
    //         nameToMarks[name]+=marks;
    //     }else if(type==2){
    //         cin >> name;
    //         auto it = nameToMarks.find(name);
    //         if(it!=nameToMarks.end()){
    //             nameToMarks.erase(it);
    //         }
    //     }else{
    //         cin >> name;
    //          cout <<Q << name  << endl;
    //         cout << nameToMarks[name] << endl;
    //     }
    // }
   

	// int n;
	// cin >> n;
	// unordered_map<string,int>dbNames;
	// while(n--){
	// 	string s;
	// 	cin >> s;
	// 	if(dbNames[s]>0){
	// 		string newName = s+to_string(dbNames[s]);
	// 		cout<< newName<< endl;
	// 		dbNames[s]++;
	// 		dbNames[newName];
	// 	}else{
	// 		dbNames[s]++;
	// 		cout << "OK" << endl;
	// 	}
	// }
	
	
	// int n;
	// cin >> n;
	// string s;
	// cin >> s;

	// cout << minNumberOfKeyRequired(s,n);

	return 0;
}