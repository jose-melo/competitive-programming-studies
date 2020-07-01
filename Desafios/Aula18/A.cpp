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

int input[1123];
int n;

int main(){

	fastio;

	cin >> n;
	
	int somaSemana = 0;

	FOR(i, 1, 8){
		cin >> input[i];
		somaSemana += input[i];
	}

	int mult = (n / somaSemana);

	if(n % somaSemana == 0)		
		mult--;
	n -= somaSemana*mult;			

	int idx;

	FOR(i, 1, 8){
		n -= input[i];
	
		if(n <= 0){
			idx = i;
			break;
		}
	}
	
	cout << idx << "\n";
return 0;
}



