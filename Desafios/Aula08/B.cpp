#include <bits/stdc++.h>
using namespace std;

set<char> mySet;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	
	getline(cin, s);

	for(int i = 0; i < s.size(); i++)
		if('a' <= s[i] && s[i] <= 'z')
			mySet.insert(s[i]);

	cout << mySet.size() << "\n";

return 0;
}



