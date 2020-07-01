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

int input[212345];
int freq[212345];
vector<pii> ordem;
vector<int> resp;
int n, k;

bool comp(pii a, pii b){
	
	if(a.fi > b.fi)
		return true;

	if(a.fi == b.fi)
		if(a.se < b.se)
			return true;

return false;
}

int main(){

	fastio;
	
	cin >> n >> k;
	
	int aux;
	FI(n){
		cin >> aux;
		freq[aux]++;
	}

	FOR(i, 1, 200001)
		ordem.pb(mp(freq[i], i));

	sort(ordem.begin(), ordem.end(), comp);

	int cont = 0, idx = 0;
	int num = 0;
	while(cont < k){
		resp.pb(ordem[idx].se);
		cont++;
		num++;
		if(cont == k)break;

		if(ordem[idx].fi / (num+1) < ordem[idx+1].fi){
			idx++;
			num = 0;
		}
	}

	for(auto x : resp)
		cout << x << " ";
	cout << "\n";
return 0;	
}



