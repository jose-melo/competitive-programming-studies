#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int n, m;
ll x, y, k;

int main(){

	cin >> n >> m;

	cin >> x >> k >> y;

	vector<int> a, b;
	vector<pii> resto, atual;
	int mark[n+10];
	int aux;

	memset(mark, 0, sizeof(mark));
	
	FI(n){
		cin >> aux;
		a.pb(aux);
	}

	FI(m){
		cin >> aux;
		b.pb(aux);
		mark[aux] = 1;
	}

	int j = 0;
	for(int i = 0; i < n; i++){
		if(j == m || a[i] != b[j]){
			resto.pb(mp(a[i], i));
		}else{
			atual.pb(mp(a[i], i));
			j++;
		}
	}

	if(j != m){
		cout << "-1\n";
		return 0;
	}

	if(resto.empty()){
		cout << "0\n";
		return 0;
	}

	ll resp = 0;
	
	



	cout << resp << endl;



	



}

