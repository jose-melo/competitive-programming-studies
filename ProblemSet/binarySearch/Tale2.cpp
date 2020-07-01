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

int n;
vector<int> input;

int main(){

	cin >> n;

	int aux;
	FI(n){
		cin >> aux;
		input.pb(abs(aux));
	}

	sort(input.begin(), input.end());
	
	int l, r, mid;
	ll cont = 0;
	
	for(int i = 0; i < n; i++){
		l = i;
		r = n;

		while(l < r){
			mid = (l + r) / 2;		

			if(input[i] <=  2*input[mid] && input[mid] <= 2*input[i])
				l = mid + 1;
			else
				r = mid;
		}
		l--;
		cont += (l - i);
	}
	
	cout << cont << "\n";
return 0;
}








