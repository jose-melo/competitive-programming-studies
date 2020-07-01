#include <bits/stdc++.h>
using namespace std;

string res[1234567];
set <string> lista;


int main (){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	unordered_map<string, int> freq;

	bool flag = true;

	vector<string> ans;

	while(n--){

		string s; cin >> s;
		freq[s]++;
		if(freq[s]>1 && s.size()>=4){
			ans.push_back(s);
			flag = false;
		}
	}

	if(flag)
		cout << "SAFO" << "\n";
	else{
		cout << ans.size() << "\n";
		for(auto x : ans)
			cout << x << "\n";
}
}
