#include <bits/stdc++.h>
using namespace std;

int n;
string s;

map<string, int> freq;

int main(){

	cin >> n;

	cin >> s;
	

	for(int i = 0; i < s.size()-1; i++){
		if(freq.find(s.substr(i, 2)) != freq.end())
			freq[s.substr(i, 2)]++;
		else
			freq.insert(make_pair(s.substr(i, 2), 1));
		
	}
	
	int max = -1;
	string res;
	for(auto x : freq)
		if(x.second > max){
			max = x.second;
			res = x.first;
		}
	cout << res << "\n";

return 0;
}



