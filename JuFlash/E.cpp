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

	int N, M, K, v[405], cnt = 0, passei = 0;

	cin >> N >> M >> K;

	for(int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v, v+N);

	for(int i = 0; i < N; i++){
		if (v[i] > M) cnt++;
		if (v[i] == M) passei = 1;
	}

	if (cnt == 0 && !passei) cnt++;

	if (cnt <= K) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
