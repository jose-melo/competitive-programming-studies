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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;


int main(){

	int n, m;
	int a[112];
	deque<int> dq;

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int i = 1; i <= n; i++)
		dq.pb(i);

	while(dq.size() != 1){	
		if(m < a[dq.front()]){
			a[dq.front()] -= m;
			dq.pb(dq.front());
			dq.pop_front();
		}else{
			dq.pop_front();
		}
	}

	cout << dq.front() << endl;



}
