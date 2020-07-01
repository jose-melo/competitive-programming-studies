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
		#define ti cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int main() {
	
	fastio;	
	
	string s, t;
	ll n, m, start = 0, x, y, end;
	bool ok;
	
	cin >> s >> t;
	
	n = s.size();
	m = t.size();
	
	x = 0;
	y = m - 1;
	
	vector<ll> pre(m, -1), pos(m, -1);
	
	for (ll i = 0; i < m; i++) {
		ok = false;
		for (ll j = start; j < n; j++)
			if (s[j] == t[i]) {
				pre[i] = j;
				start = j + 1;
				ok = true;
				x = min(i + 1, m - 1);
				break;
			}
		if (!ok || start >= n) break;
	}
	
	if (pre[m - 1] != -1) {
		cout << t << '\n';
		return 0;
	}
			
	start = n - 1;
	for (ll i = m - 1; i >= 0; i--) {
		ok = false;
		for (ll j = start; j >= 0; j--)
			if (s[j] == t[i]) {
				pos[i] = j;
				start = j - 1;
				ok = true;
				if (y - x > max(0LL, i - 1)) {
					x = 0;
					y = max(0LL, i - 1);
				}
				break;
			}
		if (!ok || start < 0) break;
	}
			
	/*
	for (ll i = 0; i < m; i++)
		cout << pre[i] << ' ';
	cout << '\n';
	
	for (ll i = 0; i < m; i++)
		cout << pos[i] << ' ';
	cout << '\n';
	*/
	
	for (ll i = 0; i < m; i++) {
		if (pre[i] == -1) break;
		auto it = upper_bound(pos.begin() + i + 1, pos.end(), pre[i]);
		if (it != pos.end()) {
			end = it - pos.begin();
			if (end - 1 >= i + 1 && y - x > end - 1 - (i + 1)) {
				x = i + 1;
				y = end - 1;
			}
		}
		else break;
	}
	
	for (ll i = 0; i < x; i++)
		cout << t[i];
		
	for (ll i = y + 1; i < m; i++)
		cout << t[i];
		
	if (x == 0 && y == m - 1)
		cout << '-';
		
	cout << '\n';
	
	return 0;
}
