#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){

	string s;

	cin >> s;

	ll cont0 = 0;
	ll tem1 = 0;

	ll k = 0;
	while( k < s.size()){
		if(s[k] == '1')break;
		k++;	
	}
	
	for(ll i = k+1; i < s.size(); i++){
		cont0++;
		if(s[i] == '1')
			tem1 = 1;	
	}


	if(tem1)cont0++;

	if(cont0 % 2){
		cont0++;									
		cout << cont0 / 2 << endl;
		return 0;
	}

	cout << cont0/2 << "\n";
	



return 0;
}




