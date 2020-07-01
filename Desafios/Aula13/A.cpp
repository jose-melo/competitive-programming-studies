#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i = a;i < n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debugv(v) for(auto x : v) cout << x << endl;

vector<ll> cards;
ll n, k;
ll freq[30];

int main(){
	
	fastio;

	cin >> n >> k;
	string s;

	cin >> s;
	
	FI(n)
		freq[s[i]-'A']++;
	
	FOR(i, 0, 27)
		if(freq[i] != 0)
			cards.push_back(freq[i]);
	

	sort(cards.begin(), cards.end());

	
	ll faltam = k;
	ll res = 0;
	ll idx = cards.size() - 1;


	while(faltam > 0 && idx >= 0){
		if(cards[idx] < faltam){
			faltam -= cards[idx];
			res += cards[idx] * cards[idx]; 
		}else{
			res += faltam*faltam;			
			faltam = 0;	
		}
		idx--;
	}

	cout << res << "\n";
return 0;
}


