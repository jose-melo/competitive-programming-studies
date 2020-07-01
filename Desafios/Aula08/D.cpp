#include <bits/stdc++.h>
using namespace std;

#define ll long long int
map<ll, int> freq;
set<ll> faltam;

int main(){

	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	ll aux;
	for(int i = 0; i < n; i++){
		cin >> aux;
		if(freq.find(aux) != freq.end())
			freq[aux]++;
		else
			freq.insert(make_pair(aux, 1));
	}

/*	for(auto x : freq)
		cout << x.first << " " << x.second << endl;
*/
	for(auto x : freq){
		if(x.second == 1){
			faltam.insert(x.first);
		}else{
			if(x.second % 2){
				faltam.insert(x.first);
				x.second--;
			}
			int addX = x.second/2;
			if(log2(x.second) == 0 && floor(log2(x.second)) != ceil(log2(x.second)))faltam.insert(x.first + 1);
			if(freq.find(x.first + 1) != freq.end())
				freq[x.first + 1] += addX;
			else
				freq.insert(make_pair(x.first+1, addX));
		}
	}

//	for(auto x : faltam)
//		cout << x << "\n";

//	ll cont = 0;
//	int k = 0;
	set<ll>::iterator it = faltam.end();
	it--;
	ll max = *it;
	
//	cout << "max = " << max << endl;

	ll total = max + 1;
	ll res = total - faltam.size();

	cout << res << "\n";

return 0;
}
