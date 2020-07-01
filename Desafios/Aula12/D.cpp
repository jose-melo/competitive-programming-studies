#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on false
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

ll n, s;

int somaDig(ll x){
	int cont = 0;
	ll aux = x;
	ll soma = 0;

	while(aux > 1){
		cont++;
		soma += aux % 10;
		aux /= 10;
	}
return soma;
}


ll bb(ll ini, ll fim){

		
	ll l = ini, r = fim, mid, val;
	int ok = 0;
	debug(l);
	debug(r);
	while(l < r){
		
		mid = l + (r-l)/2;

		val = mid - somaDig(mid);
		if(val == s){
			ok = 1;		
			break;
		}
		if(val > s)
			r = mid;
		
		if(val < s)
			l = mid + 1;
	}

	if(ok){
		while(val == s){
			mid--;
			val = mid - somaDig(mid);
		}
		mid++;
		return mid;
	}
return l;
}


int main(){
	
	fastio;

	cin >> n >> s;

	if(s % 9 != 0)
		s = s +(9 -  (s % 9));

	cout << n - bb(0, n+1) + 1 << "\n";
return 0;
}

